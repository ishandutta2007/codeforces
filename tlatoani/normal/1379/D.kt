import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var (n, h, m, k) = jin.readLine().split(" ").map { it.toInt() }
    m /= 2
    val freights = mutableListOf<Freight>()
    for (j in 1..n) {
        val t = (jin.readLine().substringAfter(' ').toInt() + 1) % m
        freights.add(Freight(j, true, t))
        val u = t + k - 1
        if (u < m) {
            freights.add(Freight(j, false, u))
        } else {
            freights.add(Freight(j, true, 0))
            freights.add(Freight(j, false, u - m))
        }
    }
    freights.sortBy { it.time }
    if (freights[0].time > 0) {
        println("0 0")
        println()
        return
    }
    var answer = Int.MAX_VALUE
    var bestTime = 0
    var curr = 0
    for (j in freights.indices) {
        if (freights[j].add) {
            curr++
        } else {
            curr--
        }
        if ((j == freights.lastIndex || freights[j + 1].time > freights[j].time) && curr < answer) {
            answer = curr
            bestTime = freights[j].time
        }
    }
    val toRemove = mutableSetOf<Int>()
    for (j in freights.indices) {
        if (freights[j].add) {
            toRemove.add(freights[j].ix)
        } else {
            toRemove.remove(freights[j].ix)
        }
        if ((j == freights.lastIndex || freights[j + 1].time > freights[j].time) && freights[j].time == bestTime) {
            break
        }
    }
    println("$answer $bestTime")
    println(toRemove.toList().sorted().joinToString(" "))
}

data class Freight(val ix: Int, val add: Boolean, val time: Int)