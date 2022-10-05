import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    tcs@for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val houses = jin.readLine().split(" ").map { it.toLong() }.toLongArray()
        val stations = jin.readLine().split(" ").map { it.toLong() }.toLongArray()
        val alloc = LongArray(n)
        val allocLeft = LongArray(n)
        val allocRight = LongArray(n)
        allocLeft[n - 1] = min(houses[0], stations[n - 1])
        alloc[n - 1] = allocLeft[n - 1]
        allocRight[0] = houses[0] - alloc[n - 1]
        alloc[0] = allocRight[0]
        if (alloc[0] > stations[0]) {
            println("nO")
            continue@tcs
        }
        for (j in 1 until n - 1) {
            allocLeft[j - 1] = min(houses[j], stations[j - 1] - alloc[j - 1])
            alloc[j - 1] += allocLeft[j - 1]
            allocRight[j] = houses[j] - allocLeft[j - 1]
            alloc[j] += allocRight[j]
            if (alloc[j] > stations[j]) {
                println("nO")
                continue@tcs
            }
        }
        allocLeft[n - 2] = min(houses[n - 1], stations[n - 2] - alloc[n - 2])
        alloc[n - 2] += allocLeft[n - 2]
        allocRight[n - 1] = houses[n - 1] - allocLeft[n - 2]
        alloc[n - 1] += allocRight[n - 1]
        if (alloc[n - 1] > stations[n - 1]) {
            val x = alloc[n - 1] - stations[n - 1]
            if (x > allocLeft[n - 1]) {
                println("nO")
                continue@tcs
            }
            allocRight[0] += x
            alloc[0] += x
            alloc[n - 1] = stations[n - 1]
        }
        for (j in 0 until n - 1) {
            if (alloc[j] > stations[j]) {
                val x = alloc[j] - stations[j]
                if (x > allocLeft[j]) {
                    println("nO")
                    continue@tcs
                }
                allocRight[j + 1] += x
                alloc[j + 1] += x
                alloc[j] = stations[j]
            }
        }
        if (alloc[n - 1] > stations[n - 1]) {
            println("nO")
            continue@tcs
        }
        println("yEs")
    }
}