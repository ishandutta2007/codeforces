import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val left = IntArray(n + 2) { it - 1 }
    val right = IntArray(n + 2) { it + 1 }
    val id = (listOf(-1) + jin.readLine().split(" ").map { it.toInt() } + listOf(-1)).toIntArray()
    var answer = 0
    var toCheck = (1 until n).toMutableList()
    while (true) {
        val toRemove = mutableListOf<Int>()
        for (j in toCheck) {
            if (id[j] != -1 && id[right[j]] != -1 && id[j] > id[right[j]]) {
                toRemove.add(right[j])
            }
        }
        if (toRemove.isEmpty()) {
            break
        }
        toCheck.clear()
        for (j in toRemove) {
            id[j] = -1
            left[right[j]] = left[j]
            right[left[j]] = right[j]
            toCheck.add(left[j])
        }
        answer++
    }
    println(answer)
}