import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val ay = jin.readLine().split(" ").map { it.toInt() }
    if (n % 2 == 0 && ay.reduce { x, y -> x xor y } != 0) {
        println("NO")
        return
    }
    val out = StringBuilder()
    for (j in 1..n - 2 step 2) {
        out.appendln("$j ${j + 1} ${j + 2}")
    }
    for (j in 1..n - 2 step 2) {
        out.appendln("$j ${j + 1} $n")
    }
    println("YES")
    println(out.count { it == '\n' })
    print(out)
}