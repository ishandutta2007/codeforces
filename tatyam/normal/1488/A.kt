import java.util.*

val sc = Scanner(System.`in`)

fun dig(x: Int): Int {
    var x = x
    var ans = 0
    while (x > 0) {
        ans += x % 10
        x /= 10
    }
    return ans
}
fun solve() {
    val x = sc.nextInt()
    val y = sc.nextInt()
    println(y % x + dig(y / x))
}
fun main() {
    val t = sc.nextInt()
    for (i in 0 until t) solve()
}