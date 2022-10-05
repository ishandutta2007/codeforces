import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    if (n % 2 == 1) {
        println("nO")
        return
    }
    val x = LongArray(n)
    val y = LongArray(n)
    for (j in 0 until n) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        x[j] = line.substring(0, six).toLong()
        y[j] = line.substring(six + 1).toLong()
    }
    val dx = x[0] + x[n / 2]
    val dy = y[0] + y[n / 2]
    for (j in 1 until n / 2) {
        if (x[j] + x[j + (n / 2)] != dx || y[j] + y[j + (n / 2)] != dy) {
            println("nO")
            return
        }
    }
    println("yEs")
}