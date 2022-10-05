import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val array = listOf(0) + jin.readLine().split(" ").map { it.toInt() } + listOf(-1)
    val prev = IntArray(n + 2)
    val next = IntArray(n + 2)
    val length = IntArray(n + 2)
    val treeSet = TreeSet<Int>(compareBy({ -length[it] }, { it }))
    var l = 1
    while (l <= n) {
        var r = l
        while (array[r] == array[l]) {
            r++
        }
        next[l] = r
        prev[r] = l
        length[l] = r - l
        treeSet.add(l)
        l = r
    }
    var answer = 0
    while (treeSet.isNotEmpty()) {
        answer++
        l = treeSet.first()
        treeSet.remove(l)
        if (array[prev[l]] == array[next[l]]) {
            treeSet.remove(prev[l])
            treeSet.remove(next[l])
            length[prev[l]] += length[next[l]]
            next[prev[l]] = next[next[l]]
            prev[next[next[l]]] = prev[l]
            treeSet.add(prev[l])
        } else {
            next[prev[l]] = next[l]
            prev[next[l]] = prev[l]
        }
    }
    println(answer)
}

/*
13
5 5 6 6 7 7 7 7 6 5 5 5 5

 */