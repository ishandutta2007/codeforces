import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val s = jin.readLine()
        val freq = IntArray(26) { letter -> s.count { it == ('a' + letter) } }
        for (lambda in n downTo 1) {
            val g = gcd(lambda, k)
            var amt = 0
            for (f in freq) {
                amt += f / (lambda / g)
            }
            //println("lambda = $lambda, g = $g, amt = $amt")
            if (amt >= g) {
                out.appendln(lambda)
                break
            }
        }
    }
    print(out)
}

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)