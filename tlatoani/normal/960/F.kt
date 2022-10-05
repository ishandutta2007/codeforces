import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

const val LIMIT = 50

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    val adj = IntArray(n + 1)
    val edges = Array(m) {
        tokenizer = StringTokenizer(jin.readLine())
        val from = tokenizer.nextToken().toInt()
        val to = tokenizer.nextToken().toInt()
        adj[to]++
        val weight = tokenizer.nextToken().toInt()
        Edge(from, to, weight)
    }
    val dummyList = mutableListOf<Path>()
    val dummyTreeMap = TreeMap<Int, Int>()
    val lists = Array(n + 1) { dummyList }
    val treeMaps = Array(n + 1) { dummyTreeMap }
    for (j in 1..n) {
        if (adj[j] <= LIMIT) {
            lists[j] = mutableListOf()
        } else {
            treeMaps[j] = TreeMap()
        }
    }
    var answer = 0
    for (edge in edges) {
        var res = 0
        if (adj[edge.from] <= LIMIT) {
            for (path in lists[edge.from]) {
                if (path.weight < edge.weight) {
                    res = max(res, path.length)
                }
            }
        } else {
            res = treeMaps[edge.from].lowerEntry(edge.weight)?.value ?: 0
        }
        res++
        answer = max(answer, res)
        if (adj[edge.to] <= LIMIT) {
            lists[edge.to].add(Path(res, edge.weight))
        } else {
            if (res > treeMaps[edge.to].floorEntry(edge.weight)?.value ?: 0) {
                var ceiling = treeMaps[edge.to].ceilingEntry(edge.weight)
                while (ceiling != null && res >= ceiling.value) {
                    treeMaps[edge.to].remove(ceiling.key)
                    ceiling = treeMaps[edge.to].ceilingEntry(edge.weight)
                }
                treeMaps[edge.to][edge.weight] = res
            }
        }
    }
    println(answer)
}

data class Edge(val from: Int, val to: Int, val weight: Int)
data class Path(val length: Int, val weight: Int)