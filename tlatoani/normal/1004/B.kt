import java.lang.StringBuilder
import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val builder = StringBuilder()
    for (j in 0 until n) {
        builder.append(j % 2)
    }
    println(builder)
}