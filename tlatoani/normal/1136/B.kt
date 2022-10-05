import java.util.*
import java.io.*
import kotlin.math.*

fun main() {
	val (n, k) = readLine()!!.split(" ").map { it.toInt() }
	val answer = (3 * n) + min(k - 1, n - k)
	println(answer)
}