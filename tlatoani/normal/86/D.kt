import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var line = jin.readLine()
    var six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val t = line.substring(six + 1).toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    val array = IntArray(n + 1) { if (it == 0) 0 else tokenizer.nextToken().toInt() }
    val queries = Array(t) {
        line = jin.readLine()
        six = line.indexOf(' ')
        val l = line.substring(0, six).toInt()
        val r = line.substring(six + 1).toInt()
        Query(it, l, r)
    }
    queries.sort()
    val freq = LongArray(1000001)
    val answer = LongArray(t)
    var l = 1
    var r = 1
    freq[array[1]] = 1L
    var curr = array[1].toLong()
    for (query in queries) {
        while (l > query.l)  {
            l--
            freq[array[l]]++
            curr += array[l].toLong() * ((2L * freq[array[l]]) - 1L)
        }
        while (r > query.r) {
            curr -= array[r].toLong() * ((2L * freq[array[r]]) - 1L)
            freq[array[r]]--
            r--
        }
        while (r < query.r) {
            r++
            freq[array[r]]++
            curr += array[r].toLong() * ((2L * freq[array[r]]) - 1L)
        }
        while (l < query.l) {
            curr -= array[l].toLong() * ((2L * freq[array[l]]) - 1L)
            freq[array[l]]--
            l++
        }
        answer[query.j] = curr
    }
    val out = StringBuilder()
    for (j in 0 until t) {
        out.appendln(answer[j])
    }
    print(out)
}

data class Query(val j: Int, val l: Int, val r: Int): Comparable<Query> {
    override fun compareTo(other: Query) = compareValuesBy(this, other, { it.l / 450 }, { it.r })
}