import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val piles = TreeSet<Int>()
    val diffs = TreeSet<Difference>(compareBy({ it.d }, { it.x }))
    fun getAnswer(): Int {
        return if (piles.size <= 1) {
            0
        } else {
            piles.last()!! - piles.first()!! - diffs.last().d
        }
    }
    fun add(x: Int) {
        var below = piles.lower(x)
        var above = piles.higher(x)
        if (below != null && above != null) {
            diffs.remove(Difference(below, above - below))
        }
        if (below != null) {
            diffs.add(Difference(below, x - below))
        }
        if (above != null) {
            diffs.add(Difference(x, above - x))
        }
        piles.add(x)
    }
    fun remove(x: Int) {
        var below = piles.lower(x)
        var above = piles.higher(x)
        if (below != null && above != null) {
            diffs.add(Difference(below, above - below))
        }
        if (below != null) {
            diffs.remove(Difference(below, x - below))
        }
        if (above != null) {
            diffs.remove(Difference(x, above - x))
        }
        piles.remove(x)
    }
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..n) {
        add(tokenizer.nextToken().toInt())
    }
    val out = StringBuilder()
    out.appendln(getAnswer())
    for (j in 1..q) {
        val (t, x) = jin.readLine().split(" ").map { it.toInt() }
        if (t == 0) {
            remove(x)
        } else {
            add(x)
        }
        out.appendln(getAnswer())
    }
    print(out)
}

data class Difference(val x: Int, val d: Int)