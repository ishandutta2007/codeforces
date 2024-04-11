import java.lang.StringBuilder
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.min

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    val netWorth = LongArray(n + 1)
    for (j in 1..m) {
        var tokenizer = StringTokenizer(readLine()!!)
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        val d = tokenizer.nextToken().toLong()
        netWorth[b] += d
        netWorth[a] -= d
    }
    val stack = Stack<Int>()
    val debts = ArrayList<Debt>(300001)
    for (a in 1..n) {
        if (netWorth[a] != 0L) {
            while (!stack.isEmpty() && netWorth[a] > 0L && netWorth[stack.peek()] < 0L) {
                val d = min(netWorth[a], -netWorth[stack.peek()])
                debts.add(Debt(stack.peek(), a, d))
                netWorth[a] -= d
                netWorth[stack.peek()] += d
                if (netWorth[stack.peek()] == 0L) {
                    stack.pop()
                }
            }
            while (!stack.isEmpty() && netWorth[a] < 0L && netWorth[stack.peek()] > 0L) {
                val d = min(-netWorth[a], netWorth[stack.peek()])
                debts.add(Debt(a, stack.peek(), d))
                netWorth[a] += d
                netWorth[stack.peek()] -= d
                if (netWorth[stack.peek()] == 0L) {
                    stack.pop()
                }
            }
            if (netWorth[a] != 0L) {
                stack.push(a)
            }
        }
    }
    val out = StringBuilder()
    out.appendln(debts.size)
    for (debt in debts) {
        out.append(debt.a).append(' ').append(debt.b).append(' ').appendln(debt.d)
    }
    print(out)
}

data class Debt(val a: Int, val b: Int, val d: Long)