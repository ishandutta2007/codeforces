import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val array = jin.readLine().split(" ").map { it.toLong() }
    val prefixes = LongArray(n + 1)
    for (j in 1..n) {
        prefixes[j] = gcd(array[j - 1], prefixes[j - 1])
    }
    val suffixes = LongArray(n + 1)
    for (j in n - 1 downTo 0) {
        suffixes[j] = gcd(array[j], suffixes[j + 1])
    }
    var answer = 1L
    for (j in 1..n) {
        answer = lcm(answer, gcd(prefixes[j - 1], suffixes[j]))
    }
    println(answer)
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)
fun lcm(a: Long, b: Long) = (a * b) / gcd(a, b)