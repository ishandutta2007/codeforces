import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    val permutations = mutableListOf<List<Int>>()
    for (a in 0..3) {
        for (b in 0..3) {
            for (c in 0..3) {
                for (d in 0..3) {
                    if (setOf(a, b, c, d).size == 4) {
                        permutations.add(listOf(a, b, c, d))
                    }
                }
            }
        }
    }
    repeat(jin.readLine().toInt()) {
        val s = jin.readLine().map { when (it) {
            'A' -> 0
            'T' -> 2
            'O' -> 3
            else -> 1
        } }
        val freqs = LongArray(4)
        val inversions = Array(4) { LongArray(4) }
        for (x in s) {
            for (y in 0..3) {
                inversions[y][x] += freqs[y]
            }
            freqs[x]++
        }
        var bestPermutation = permutations[0]
        var optimal = 0L
        for (p in permutations) {
            var amt = 0L
            for (j in 0..3) {
                for (k in 0 until j) {
                    amt += inversions[p[j]][p[k]]
                }
            }
            if (amt > optimal) {
                bestPermutation = p
                optimal = amt
            }
        }
        for (x in bestPermutation) {
            out.append("ANTO"[x].toString().repeat(freqs[x].toInt()))
        }
        out.appendln()
    }
    print(out)
}