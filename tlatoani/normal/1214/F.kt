import java.util.*
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val m = jin.nextLong()
    val n = jin.nextInt()
    var jobs = Array(n) { j -> ComparablePair(jin.nextLong(), j) }
    var ponas = Array(n) { i -> ComparablePair(jin.nextLong(), i + 1) }
    jobs.sort()
    ponas.sort()
    val ponasMap = TreeMap<Long, Int>()
    for (j in n - 1 downTo 0) {
        ponasMap[ponas[j].city] = j
        ponasMap[ponas[j].city + m] = j + n
        ponasMap[ponas[j].city + (2L * m)] = j + (2 * n)
    }
    val jobsMap = TreeMap<Long, Int>()
    for (j in 0 until n) {
        jobsMap[jobs[j].city] = j
        jobsMap[jobs[j].city - m] = j - n
        jobsMap[jobs[j].city - (2L * m)] = j - (2 * n)
    }
    var curr: Long = 0
    val diffs = LongArray(n)
    for (j in 0 until n) {
        val dist = abs(jobs[j].city - ponas[j].city)
        curr += min(dist, m - dist)
        var k1 = ponasMap.higherEntry(jobs[j].city)
        var k2 = ponasMap.higherEntry(jobs[j].city + (m / 2L))
        //println("jobs[$j].city = ${jobs[j].city}, k1 = $k1, k2 = $k2")
        if (k1.key - jobs[j].city <= m / 2 && k2.key - jobs[j].city <= m) {
            diffs[(n + k1.value - j) % n] -= 2L * jobs[j].city
            diffs[(n + k2.value - j) % n] += 2L * jobs[j].city
        }
        if (jobs[j].city + (m / 2L) > m) {
            diffs[(n - j) % n] += m
            diffs[(n + k2.value - j) % n] -= m
        } else {
            diffs[(n + k2.value - j) % n] += m
            diffs[(n - j) % n] -= m
        }
        //println("diffs = ${diffs.contentToString()}")
        k1 = jobsMap.lowerEntry(ponas[j].city)
        k2 = jobsMap.lowerEntry(ponas[j].city - (m / 2L))
        //println("ponas[$j].city = ${ponas[j].city}, k1 = $k1, k2 = $k2")
        if (ponas[j].city - k1.key <= m / 2 && ponas[j].city - k2.key <= m) {
            diffs[(n + j - k1.value) % n] += 2L * ponas[j].city
            diffs[(n + j - k2.value) % n] -= 2L * ponas[j].city
        }
        //println("diffs = ${diffs.contentToString()}")
    }
    var answer = curr
    var ai = 0
    //println("i = 0, curr = $curr")
    for (i in 1 until n) {
        curr += diffs[i]
        if (curr < answer) {
            answer = curr
            ai = i
        }
        //println("i = $i, curr = $curr")
    }
    println(answer)
    val answerPonas = IntArray(n)
    for (j in 0 until n) {
        answerPonas[jobs[j].ix] = ponas[((ai + j) % n)].ix
    }
    println(answerPonas.joinToString(" ", "", ""))
}

data class ComparablePair(val city: Long, val ix: Int): Comparable<ComparablePair> {
    override fun compareTo(other: ComparablePair) = city.compareTo(other.city)
}