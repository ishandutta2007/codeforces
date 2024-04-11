import java.text.DecimalFormat
import kotlin.math.abs
import kotlin.math.sqrt

fun main() {
    fun format(x: Double) = DecimalFormat("0.00").format(x)
    var answer = mutableListOf<String>()
    for (c in 1..11) {
        val k = readLine()!!.toInt()
        val x = k.toDouble()
        val res = (5.0 * x * x * x) + sqrt(abs(x))
        if (res < 400.0) {
            answer.add("f($k) = ${format(res)}")
        } else {
            answer.add("f($k) = MAGNA NIMIS!")
        }
    }
    println(answer.reversed().joinToString("\n"))
}