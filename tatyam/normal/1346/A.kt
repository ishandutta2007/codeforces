import java.util.*
val scanner = Scanner(System.`in`)

fun solve() {
    val n = scanner.nextInt()
    val k = scanner.nextInt()
    val a = n / (1 + k + k * k + k * k * k)
    println("$a ${a*k} ${a*k*k} ${a*k*k*k}")
}

fun main() {
    val t = scanner.nextInt()
    for(i in 0 until t) solve()
}