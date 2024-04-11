import java.util.*
import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min

val readQueue = ArrayDeque<String>()

fun getInput(): String {
    if (readQueue.isEmpty()) readLine()!!.split(' ', '\n').let { readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt() = getInput().toInt()
fun getDouble() = getInput().toDouble()
fun getString() = getInput()
fun getLong() = getInput().toLong()

fun <T> printv(v: Collection<T>) {
    v.forEachIndexed { i, t ->
        if (i != 0) print(" ")
        print(t)
    }
    println()
}

fun <T : Comparable<T>> lsort(v: MutableList<T>) {
    v.sort()
}

fun <T : Comparable<T>> gsort(v: MutableList<T>) {
    v.sortDescending()
}

fun <T, U> mp(t: T, u: U) = Pair(t, u)

fun ifloor(a: Int, b: Int) = if (a xor b > 0) a / b else (a - b + 1) / b
fun iceil(a: Int, b: Int) = if (a xor b > 0) (a + b - 1) / b else a / b
fun ifloor(a: Long, b: Long) = if (a xor b > 0) a / b else (a - b + 1) / b
fun iceil(a: Long, b: Long) = if (a xor b > 0) (a + b - 1) / b else a / b

typealias ll = Long
typealias pii = Pair<Int, Int>
typealias pll = Pair<ll, ll>

val MOD = 1000000007L
val MAX = 2147483647L

fun <T> List<T>.binarySearchWith(condition: (T) -> Boolean): Int {
    return binarySearch {
        if (condition(it)) 1
        else -1
    }.let { -(it + 1) }
}

fun List<Int>.lowerBound(i: Int): Int {
    return binarySearchWith { it >= i }
}

fun List<Int>.upperBound(i: Int): Int {
    return binarySearchWith { it > i }
}

fun main() {

    1.rangeTo(readLine()!!.toInt()).forEach{
        readLine()!!.toInt().let { n ->
            List(n) { if (it < (n - 1) / 2) 1 else if (n - 2 - it < (n - 1) / 2) -1 else 0 }.let { a ->
                StringBuilder().also { b ->
                    (n - 1).downTo(1).forEach { for (i in 0 until it) b.append("${a[i]}\n") }
                }.toString().let { print(it) }
            }
        }
    }

}