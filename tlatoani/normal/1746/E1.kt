import java.util.*
import kotlin.system.exitProcess

fun main() {
    val n = readLine()!!.toInt()
    var rem = (1..n).toList()
    fun query(from: Int, to: Int): Boolean {
        val joiner = StringJoiner(" ", "? ${to - from} ", "")
        for (j in from until to) {
            joiner.add(rem[j].toString())
        }
        println(joiner)
        return readLine()!! == "YES"
    }
    fun answer(x: Int) {
        println("! $x")
        if (readLine()!! == ":)") {
            exitProcess(0)
        }
    }
    fun remove(from: Int, to: Int) {
        rem = rem.subList(0, from) + rem.subList(to, rem.size)
    }
    while (rem.size > 3) {
        val a = rem.size / 4
        val b = rem.size / 2
        val c = (3 * rem.size) / 4
        val d = rem.size
        if (query(b, d)) {
            if (query(a, d)) {
                remove(0, a)
            } else {
                remove(a, b)
            }
        } else {
            if (query(c, d)) {
                remove(b, c)
            } else {
                remove(c, d)
            }
        }
    }
    if (rem.size == 3) {
        if (query(0, 2) && query(0, 2)) {
            remove(2, 3)
        } else {
            if (query(0, 1)) {
                remove(1, 2)
            } else {
                remove(0, 1)
            }
        }
    }
    for (x in rem) {
        answer(x)
    }
}