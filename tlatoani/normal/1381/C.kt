import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, x, y) = jin.readLine().split(" ").map { it.toInt() }
        val bob = jin.readLine().split(" ").map { it.toInt() }
        val freq = IntArray(n + 2)
        for (b in bob) {
            freq[b]++
        }
        var unused = 1
        while (freq[unused] > 0) {
            unused++
        }
        val spots = mutableListOf<Spot>()
        for (j in 0 until n) {
            spots.add(Spot(j, bob[j], freq[bob[j]]))
            freq[bob[j]]--
        }
        spots.sortByDescending { it.freq }
        val answer = IntArray(n)
        val used = BooleanArray(n)
        for (j in 0 until x) {
            used[spots[j].ix] = true
            answer[spots[j].ix] = bob[spots[j].ix]
        }
        for (j in 0 until n) {
            if (!used[j]) {
                freq[bob[j]]++
            }
        }
        spots.clear()
        val remColors = mutableListOf<Int>()
        for (j in 0 until n) {
            if (!used[j]) {
                spots.add(Spot(j, bob[j], freq[bob[j]]))
                remColors.add(bob[j])
                freq[bob[j]]--
            }
        }
        spots.sortByDescending { it.freq }
        for (j in 0 until n - y) {
            used[spots[j].ix] = true
            answer[spots[j].ix] = unused
        }
        spots.clear()
        for (j in 0 until n) {
            if (!used[j]) {
                freq[bob[j]]++
                spots.add(Spot(j, bob[j], 0))
            }
        }
        var highColor = 0
        for (k in 1..n + 1) {
            if (freq[k] > (y - x) / 2) {
                highColor = k
            }
        }
        if (highColor == 0) {
            spots.sortBy { it.color }
            for (j in 0 until y - x) {
                answer[spots[j].ix] = bob[spots[(j + ((y - x) / 2)) % (y - x)].ix]
            }
        } else {
            var newRemColors = LinkedList<Int>()
            for (k in remColors) {
                if (k != highColor) {
                    newRemColors.add(k)
                }
            }
            for (spot in spots) {
                if (spot.color == highColor) {
                    if (newRemColors.isEmpty()) {
                        break
                    }
                    answer[spot.ix] = newRemColors.remove()
                } else {
                    answer[spot.ix] = highColor
                }
            }
        }
        var checkX = 0
        for (j in 0 until n) {
            if (bob[j] == answer[j]) {
                checkX++
            }
        }
        val checkBob = IntArray(n + 2)
        val checkAnswer = IntArray(n + 2)
        for (b in bob) {
            checkBob[b]++
        }
        for (a in answer) {
            checkAnswer[a]++
        }
        var checkY = 0
        for (k in 1..n + 1) {
            checkY += min(checkBob[k], checkAnswer[k])
        }
        if (checkX == x && checkY == y && answer.all { it != 0 }) {
            out.appendln("YES")
            out.appendln(answer.joinToString(" "))
        } else {
            out.appendln("NO")
        }
    }
    print(out)
}

data class Spot(val ix: Int, val color: Int, val freq: Int)

/*

1
6 1 2
3 2 1 1 1 1


 */