const val ALL = (1 shl 18) - 1
val DUMMY = Edge(-1, -1)

fun main() {
    val n = readLine()!!.toInt()
    val ages = listOf(0) + readLine()!!.split(" ").map { it.toInt() }.sorted()
    var answer = 0L
    for (age in ages) {
        answer -= age.toLong()
    }
    val components = (0..n).toMutableSet()
    val union = IntArray(ages.size) { it }
    val members = Array(ages.size) { mutableListOf(it) }
    val dp = Array(2) { IntArray(1 shl 18) }
    while (components.size > 1) {
        val componentList = components.toList()
        val edges = Array(componentList.size) { DUMMY }
        dp.forEach { it.fill(-1) }
        for (k in 0..n) {
            if (k > dp[0][ages[k]]) {
                if (dp[0][ages[k]] != -1 && union[dp[0][ages[k]]] != union[k]) {
                    dp[1][ages[k]] = dp[0][ages[k]]
                }
                dp[0][ages[k]] = k
            } else if (union[k] != union[dp[0][ages[k]]] && k > dp[1][ages[k]]) {
                dp[1][ages[k]] = k
            }
        }
        for (mask in 0..ALL) {
            for (e in 0..17) {
                if ((mask shr e) and 1 != 0) {
                    var pos = dp[0][mask - (1 shl e)]
                    if (pos > dp[0][mask]) {
                        if (dp[0][mask] != -1 && union[dp[0][mask]] != union[pos]) {
                            dp[1][mask] = dp[0][mask]
                        }
                        dp[0][mask] = pos
                    } else if (pos > dp[1][mask] && union[pos] != union[dp[0][mask]]) {
                        dp[1][mask] = pos
                    }
                    pos = dp[1][mask - (1 shl e)]
                    if (pos > dp[1][mask] && union[pos] != union[dp[0][mask]]) {
                        dp[1][mask] = pos
                    }
                }
            }
        }
        for (j in componentList.indices) {
            for (k in members[componentList[j]]) {
                var k2 = dp[0][ALL - ages[k]]
                if (k2 != -1 && union[k2] == union[k]) {
                    k2 = dp[1][ALL - ages[k]]
                }
                if (k2 != -1 && (edges[j].a == -1 || ages[k] + ages[k2] > ages[edges[j].a] + ages[edges[j].b])) {
                    edges[j] = Edge(k, k2)
                }
            }
        }
        edges.sortByDescending { if (it.a == -1) -1 else ages[it.a] + ages[it.b] }
        for (edge in edges) {
            if (edge.a != -1) {
                val u = union[edge.a]
                val v = union[edge.b]
                if (u != v) {
                    answer += (ages[edge.a] + ages[edge.b]).toLong()
                    if (members[u].size > members[v].size) {
                        members[v].forEach { union[it] = u }
                        members[u].addAll(members[v])
                        components.remove(v)
                    } else {
                        members[u].forEach { union[it] = v }
                        members[v].addAll(members[u])
                        components.remove(u)
                    }
                }
            }
        }
    }
    println(answer)
}

data class Edge(val a: Int, val b: Int)