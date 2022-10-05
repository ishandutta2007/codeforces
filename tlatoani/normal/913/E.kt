import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val X = 0b00001111
const val Y = 0b00110011
const val Z = 0b01010101

fun main() {
    val comparator = kotlin.Comparator<Expression> { e1, e2 ->
        if (e1.string.length != e2.string.length) {
            e1.string.length - e2.string.length
        } else {
            e1.string.compareTo(e2.string)
        }
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val answer = Array(3) { Array(256) { Expression(-1, "", -1)} }
    val expressions = mutableListOf<Expression>()
    val pq = PriorityQueue<Expression>(comparator)
    pq.add(Expression(X, "x", 0))
    pq.add(Expression(Y, "y", 0))
    pq.add(Expression(Z, "z", 0))
    var rem = 256 * 3
    while (rem > 0) {
        val expr = pq.remove()
        var j = expr.priority
        if (answer[j][expr.value].value != -1) {
            continue
        }
        while (j < 3 && answer[j][expr.value].value == -1) {
            rem--
            answer[j][expr.value] = expr
            j++
        }
        if (expr.priority == 0) {
            pq.add(Expression(255 xor expr.value, "!" + expr.string, 0))
        }
        expressions.add(expr)
        for (other in expressions) {
            if (expr.priority <= 1 && other.priority <= 1) {
                pq.add(Expression(expr.value and other.value, expr.string + "&" + other.string, 1))
                pq.add(Expression(expr.value and other.value, other.string + "&" + expr.string, 1))
            }
            pq.add(Expression(expr.value or other.value, expr.string + "|" + other.string, 2))
            pq.add(Expression(expr.value or other.value, other.string + "|" + expr.string, 2))
        }
        pq.add(Expression(expr.value, "(" + expr.string + ")", 0))
    }
    for (c in 1..jin.readLine().toInt()) {
        val f = jin.readLine().toInt(2)
        println(answer[2][f].string)
    }
}

data class Expression(val value: Int, val string: String, val priority: Int)