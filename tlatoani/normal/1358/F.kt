import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val array = jin.readLine().split(" ").map { it.toLong() }
    val brray = jin.readLine().split(" ").map { it.toLong() }.toMutableList()
    if (n == 1) {
        if (array[0] == brray[0]) {
            println("SMALL")
            println(0)
            println()
        } else {
            println("IMPOSSIBLE")
        }
        return
    } else if (n == 2) {
        val mexico = array.max()!!
        val minimo = array.min()!!
        var a = brray.max()!!
        var b = brray.min()!!
        var prefixes = 0L
        while (a != mexico || b != minimo) {
            if (b < minimo || a < mexico) {
                println("IMPOSSIBLE")
                return
            }
            if (b > minimo) {
                prefixes += a / b
                a %= b
                val c = a
                a = b
                b = c
            } else if (a % b == mexico % b) {
                prefixes += (a - mexico) / b
                break
            } else {
                println("IMPOSSIBLE")
                return
            }
        }
        if (prefixes > 200000L) {
            println("BIG")
            println(prefixes)
            return
        }
    }
    val answer = StringBuilder()
    var reversed = false
    while ((0 until n).any { array[it] != brray[it] }) {
        if ((0 until n).all { array[it] == brray[n - 1 - it] }) {
            answer.append('R')
            break
        }
        when {
            (1 until n).all { brray[it] >= brray[it - 1] } -> {
                answer.append('P')
                reversed = false
                for (j in n - 1 downTo 1) {
                    brray[j] -= brray[j - 1]
                }
            }
            reversed -> {
                println("IMPOSSIBLE")
                return
            }
            else -> {
                answer.append('R')
                reversed = true
                brray.reverse()
            }
        }
        if ((0 until n).any { brray[it] <= 0L }) {
            println("IMPOSSIBLE")
            return
        }
    }
    if (answer.count { it == 'P' } > 200000) {
        println("BIG")
        println(answer.count { it == 'P' })
    } else {
        println("SMALL")
        println(answer.length)
        println(answer.reversed())
    }
}