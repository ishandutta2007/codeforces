import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val book = IntArray(200001)
    var l = 1
    var r = 0
    val out = StringBuilder()
    for (j in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val type = line[0]
        val id = line[1].toInt()
        when (type) {
            "L" -> {
                l--
                book[id] = l
            }
            "R" -> {
                r++
                book[id] = r
            }
            "?" -> {
                out.appendln(min(book[id] - l, r - book[id]))
            }
        }
    }
    print(out)
}