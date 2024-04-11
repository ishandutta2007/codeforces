import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toInt() }
        var z = ay.reduce { x, y -> x xor y }
        if (z == 0) {
            out.appendln("DRAW")
        } else {
            var b = 1 shl 29
            while (z and b == 0) {
                b /= 2
            }
            var x = 0
            for (a in ay) {
                if (a and b != 0) {
                    x++
                }
            }
            if (((x + 1) / 2) % 2 == 1 || (n - x) % 2 == 1) {
                out.appendln("WIN")
            } else {
                out.appendln("LOSE")
            }
        }
    }
    print(out)
}