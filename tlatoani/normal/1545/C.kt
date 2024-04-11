const val MOD = 998244353L

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val permutations = Array(2 * n) { readLine()!!.split(" ").map { it.toInt() - 1 } }
        val appearances = Array(n) { Array(n) { mutableSetOf<Int>() } }
        for (a in 0 until 2 * n) {
            for (k in 0 until n) {
                appearances[k][permutations[a][k]].add(a)
            }
        }
        val disp = BooleanArray(2 * n) { true }
        val dummy = mutableSetOf<Int>()
        val answerSubset = mutableListOf<Int>()
        fun remove(a: Int, used: Boolean) {
            if (disp[a]) {
                disp[a] = false
                if (used) {
                    answerSubset.add(a + 1)
                }
                for (k in 0 until n) {
                    appearances[k][permutations[a][k]].remove(a)
                    if (used) {
                        val there = appearances[k][permutations[a][k]]
                        appearances[k][permutations[a][k]] = dummy
                        for (b in there) {
                            remove(b, false)
                        }
                    } else {
                        if (appearances[k][permutations[a][k]].size == 1) {
                            remove(appearances[k][permutations[a][k]].max()!!, true)
                        }
                    }
                }
            }
        }
        for (r in 0 until n) {
            for (s in 0 until n) {
                if (appearances[r][s].size == 1) {
                    remove(appearances[r][s].max()!!, true)
                }
            }
        }
        var answerAMT = 1L
        fun dfs(a: Int, parity: Boolean) {
            if (disp[a]) {
                disp[a] = false
                if (parity) {
                    answerSubset.add(a + 1)
                }
                for (k in 0 until n) {
                    for (b in appearances[k][permutations[a][k]]) {
                        dfs(b, !parity)
                    }
                }
            }
        }
        for (r in 0 until 2 * n) {
            if (disp[r]) {
                answerAMT *= 2L
                answerAMT %= MOD
                dfs(r, true)
            }
        }
        println(answerAMT)
        println(answerSubset.joinToString(" "))
    }
}