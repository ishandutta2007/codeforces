import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        var tokenizer = StringTokenizer(jin.readLine())
        val r = tokenizer.nextToken().toInt()
        val g = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        tokenizer = StringTokenizer(jin.readLine())
        val redGems = LongArray(r) { tokenizer.nextToken().toLong() }
        tokenizer = StringTokenizer(jin.readLine())
        val greenGems = LongArray(g) { tokenizer.nextToken().toLong() }
        tokenizer = StringTokenizer(jin.readLine())
        val blueGems = LongArray(b) { tokenizer.nextToken().toLong() }
        val gems = ArrayList<Gem>(r + g + b)
        val redTreeSet = TreeSet<Long>()
        val greenTreeSet = TreeSet<Long>()
        val blueTreeSet = TreeSet<Long>()
        for (weight in redGems) {
            gems.add(Gem(0, weight))
            redTreeSet.add(weight)
        }
        for (weight in greenGems) {
            gems.add(Gem(1, weight))
            greenTreeSet.add(weight)
        }
        for (weight in blueGems) {
            gems.add(Gem(2, weight))
            blueTreeSet.add(weight)
        }
        gems.sortBy { it.weight }
        var lastRed = -1L
        var lastGreen = -1L
        var lastBlue = -1L
        var answer = Long.MAX_VALUE
        for (gem in gems) {
            when (gem.color) {
                0 -> lastRed = gem.weight
                1 -> lastGreen = gem.weight
                2 -> lastBlue = gem.weight
            }
            val min = minOf(lastRed, lastGreen, lastBlue)
            val max = maxOf(lastRed, lastGreen, lastBlue)
            if (min != -1L) {
                val mid = lastRed + lastGreen + lastBlue - min - max
                if (lastRed == mid) {
                    val left = redTreeSet.floor((lastGreen + lastBlue) / 2L) ?: lastRed
                    val right = redTreeSet.ceiling((lastGreen + lastBlue) / 2L) ?: lastRed
                    answer = minOf(answer, calc(left, lastGreen, lastBlue), calc(right, lastGreen, lastBlue))
                } else if (lastGreen == mid) {
                    val left = greenTreeSet.floor((lastRed + lastBlue) / 2L) ?: lastGreen
                    val right = greenTreeSet.ceiling((lastRed + lastBlue) / 2L) ?: lastGreen
                    answer = minOf(answer, calc(lastRed, left, lastBlue), calc(lastRed, right, lastBlue))
                } else {
                    val left = blueTreeSet.floor((lastRed + lastGreen) / 2L) ?: lastBlue
                    val right = blueTreeSet.ceiling((lastRed + lastGreen) / 2L) ?: lastBlue
                    answer = minOf(answer, calc(lastRed, lastGreen, left), calc(lastRed, lastGreen, right))
                }
            }
        }
        out.appendln(answer)
    }
    print(out)
}

fun calc(red: Long, green: Long, blue: Long) = ((red - green) * (red - green)) + ((green - blue) * (green - blue)) + ((blue - red) * (blue - red))

data class Gem(val color: Int, val weight: Long)