import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val joiner = StringJoiner(" ")
    val n = jin.nextInt()
    val coolness1 = IntArray(n) { jin.nextInt() }
    var highest = 0
    var lowest = 1 shl 30
    for (c in coolness1) {
        highest = max(highest, c)
        lowest = min(lowest, c)
    }
    if (highest <= 2 * lowest) {
        for (i in 0 until n) {
            joiner.add("-1")
        }
        println(joiner)
        return
    }
    val coolness3 = IntArray(3 * n) { i -> coolness1[i % n] }
    val tracks = TreeSet<Track>()
    var j = 0
    for (i in 0 until n) {
        while (j < 3 * n && (tracks.isEmpty() || 2 * coolness3[j] >= tracks.last().coolness)) {
            tracks.add(Track(j, coolness3[j]))
            j++
        }
        joiner.add((j - i).toString())
        tracks.remove(Track(i, coolness1[i]))
    }
    println(joiner)
}

data class Track(val k: Int, val coolness: Int): Comparable<Track> {
    override fun compareTo(other: Track) = compareValuesBy(this, other, { it.coolness }, { it.k })
}