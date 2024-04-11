import java.util.*
import kotlin.math.*

val scanner = Scanner(System.`in`)
val INF = 0x3fffffff

fun solve() {
    val n = scanner.nextInt()
    val m = scanner.nextInt()
    val ans = Array(n) { 0 }
    val edge = Array(m) { Triple(scanner.nextInt() - 1,  scanner.nextInt() - 1,  scanner.nextInt()) }
    for ((a, b, x) in edge) {
        ans[a] = max(ans[a], x)
        ans[b] = max(ans[b], x)
    }
    for ((a, b, x) in edge) if (min(ans[a], ans[b]) != x) {
        println("NO")
        return
    }
    println("YES")
    for (i in ans) print("$i ")
    println()
}

fun main() {
    val t = scanner.nextInt()
    for(i in 0 until t) solve()
}