import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        var n = jin.readLine().toLong()
        var div3 = 0
        while (n % 3L == 0L) {
            n /= 3L
            div3++
        }
        var div2 = 0
        while (n % 2L == 0L) {
            n /= 2L
            div2++
        }
        if (n == 1L && div2 <= div3) {
            println(div3 + div3 - div2)
        } else {
            println(-1)
        }
    }
}