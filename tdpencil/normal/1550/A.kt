import java.util.*

import kotlin.math.*

fun main() {
    val T = readLine()!!.toInt()

    repeat(T) {
        val N = readLine()!!.toInt()

        println(ceil(sqrt(N.toDouble())).toInt())
    }
}