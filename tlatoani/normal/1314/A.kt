import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    var tokenizer = StringTokenizer(readLine()!!)
    val publications = Array(n) { Pair(it, tokenizer.nextToken().toInt()) }
    publications.sortBy { it.second }
    tokenizer = StringTokenizer(readLine()!!)
    val time = LongArray(n) { tokenizer.nextToken().toLong() }
    var amt = 0
    var answer = 0L
    val pq = PriorityQueue<Int>(compareBy { -time[it] })
    var currTime = 0L
    var j = 0
    while (j < n || pq.isNotEmpty()) {
        if (pq.isEmpty()) {
            amt = publications[j].second
            pq.clear()
        }
        while (j < n && publications[j].second == amt) {
            currTime += time[publications[j].first]
            pq.add(publications[j].first)
            j++
        }
        currTime -= time[pq.remove()]
        answer += currTime
        amt++
    }
    println(answer)
}