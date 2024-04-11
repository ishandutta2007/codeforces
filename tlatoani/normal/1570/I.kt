import kotlin.math.min

const val BLOCK = 2000

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val array = (listOf(0) + readLine()!!.split(" ").map { it.toInt() }).toIntArray()
    val changeIndex = IntArray(m + 1)
    val changeFrom = IntArray(m + 1)
    val changeTo = IntArray(m + 1)
    val queries = mutableListOf<Query>()
    for (t in 1..m) {
        val line = readLine()!!.split(" ").map { it.toInt() }
        if (line[0] == 1) {
            queries.add(Query(t, line[1], line[2], line[3]))
        } else {
            changeIndex[t] = line[1]
            changeFrom[t] = array[changeIndex[t]]
            array[changeIndex[t]] = line[2]
            changeTo[t] = array[changeIndex[t]]
        }
    }
    val freqs = IntArray(400)
    val indexes = IntArray(n + 1)
    var size = 1
    val amt = IntArray(n + 1)
    val freq = IntArray(100001)
    amt[0] = n + 1
    fun increase(x: Int) {
        if (amt[freq[x] + 1] == 0) {
            indexes[freq[x] + 1] = size
            freqs[size] = freq[x] + 1
            size++
        }
        amt[freq[x]]--
        freq[x]++
        amt[freq[x]]++
        if (amt[freq[x] - 1] == 0) {
            size--
            freqs[indexes[freq[x] - 1]] = freqs[size]
            indexes[freqs[size]] = indexes[freq[x] - 1]
        }
    }
    fun decrease(x: Int) {
        if (amt[freq[x] - 1] == 0) {
            indexes[freq[x] - 1] = size
            freqs[size] = freq[x] - 1
            size++
        }
        amt[freq[x]]--
        freq[x]--
        amt[freq[x]]++
        if (amt[freq[x] + 1] == 0) {
            size--
            val j = indexes[freq[x] + 1]
            val x = freqs[size]
            freqs[j] = x
            indexes[x] = j
        }
    }
    var l = 1
    var r = 1
    var t = m
    increase(array[1])
    val answers = IntArray(m + 1) { Int.MAX_VALUE }
    queries.sortWith(compareBy({ it.from / BLOCK }, { it.to / BLOCK }, { it.time }))
    for ((time, from, to, k) in queries) {
        while (t < time) {
            t++
            if (changeIndex[t] in l..r) {
                decrease(changeFrom[t])
                increase(changeTo[t])
            }
            array[changeIndex[t]] = changeTo[t]
        }
        while (t > time) {
            if (changeIndex[t] in l..r) {
                decrease(changeTo[t])
                increase(changeFrom[t])
            }
            array[changeIndex[t]] = changeFrom[t]
            t--
        }
        while (l > from) {
            l--
            increase(array[l])
        }
        while (r < to) {
            r++
            increase(array[r])
        }
        while (l < from) {
            decrease(array[l])
            l++
        }
        while (r > to) {
            decrease(array[r])
            r--
        }
        freqs.sort(fromIndex = 0, toIndex = size)
        var j2 = 1
        var currAMT = amt[freqs[1]]
        fLoop@for (j in 1 until size) {
            while (currAMT < k) {
                j2++
                if (j2 == size) {
                    break@fLoop
                }
                currAMT += amt[freqs[j2]]
            }
            answers[t] = min(answers[t], freqs[j2] - freqs[j])
            currAMT -= amt[freqs[j]]
        }
        for (j in 0 until size) {
            indexes[freqs[j]] = j
        }
    }
    val out = StringBuilder()
    for (t in 1..m) {
        if (changeIndex[t] == 0) {
            out.appendln(if (answers[t] == Int.MAX_VALUE) -1 else answers[t])
        }
    }
    print(out)
}

data class Query(val time: Int, val from: Int, val to: Int, val k: Int)