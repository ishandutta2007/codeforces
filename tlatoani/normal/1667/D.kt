fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val adj = Array(n + 1) { mutableListOf<Int>() }
        repeat(n - 1) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        val r = (1..n).find { adj[it].size == 1 }!!
        val types = IntArray(n + 1)
        fun calcType(a: Int, parent: Int) {
            val freqs = IntArray(4)
            for (b in adj[a]) {
                if (b != parent) {
                    calcType(b, a)
                    freqs[types[b]]++
                }
            }
            if (freqs[0] > 0) {
                return
            }
            val degree = adj[a].size
            val up = (degree + 1) / 2
            val down = degree / 2
            if (up >= 1 && freqs[1] + freqs[3] >= up - 1 && freqs[2] + freqs[3] >= down) {
                types[a] += 1
            }
            if (down >= 1 && freqs[1] + freqs[3] >= up && freqs[2] + freqs[3] >= down - 1) {
                types[a] += 2
            }
        }
        val s = adj[r].first()
        calcType(s, r)
        val answer = types[s] and 1 == 1
        if (answer) {
            out.appendln("YES")
            val constructionStart = mutableListOf<Pair<Int, Int>>()
            val constructionEnd = mutableListOf<Pair<Int, Int>>()
            fun construct(a: Int, parent: Int) {
                val degree = adj[a].size
                val up = (degree + 1) / 2
                val down = degree / 2
                val upEdges = mutableListOf<Int>()
                val downEdges = mutableListOf<Int>()
                if (types[a] == 1) {
                    upEdges.add(parent)
                } else {
                    downEdges.add(parent)
                }
                for (b in adj[a]) {
                    if (b != parent && types[b] != 3) {
                        if (types[b] == 1) {
                            upEdges.add(b)
                        } else {
                            downEdges.add(b)
                        }
                    }
                }
                for (b in adj[a]) {
                    if (b != parent && types[b] == 3) {
                        if (upEdges.size < up) {
                            types[b] = 1
                            upEdges.add(b)
                        } else {
                            types[b] = 2
                            downEdges.add(b)
                        }
                    }
                }
                for (b in adj[a]) {
                    if (b != parent) {
                        construct(b, a)
                    }
                }
                for (j in 0 until degree) {
                    val b = (if (j % 2 == 0) upEdges else downEdges)[j / 2]
                    if (b == parent) {
                        break
                    }
                    constructionStart.add(Pair(a, b))
                }
                for (j in degree - 1 downTo 0) {
                    val b = (if (j % 2 == 0) upEdges else downEdges)[j / 2]
                    if (b == parent) {
                        break
                    }
                    constructionEnd.add(Pair(a, b))
                }
            }
            construct(s, r)
            val construction = constructionEnd + listOf(Pair(r, s)) + constructionStart.reversed()
            for ((a, b) in construction) {
                out.appendln("$a $b")
            }
        } else {
            out.appendln("NO")
        }
    }
    print(out)
}