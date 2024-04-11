import java.util.*
import kotlin.math.min

val scanner = Scanner(System.`in`)

fun solve() {
    val n = scanner.nextInt()
    val k1 = scanner.nextInt()
    val k2 = min(scanner.nextInt(), k1 * 2)
    val s = scanner.next()
    var i = 0
    var ans = 0
    while (i < n) {
        if (s[i] == '0') {
            i++
        }
        else {
            if (i + 1 < n && s[i + 1] == '1') {
                ans += k2
                i += 2
            }
            else {
                ans += k1
                i++
            }
        }
    }
    println("$ans")
}

fun main() {
    val t = scanner.nextInt()
    for(i in 0 until t) solve()
}