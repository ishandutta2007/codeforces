import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    val voters = mutableListOf<Voter>()
    var curr = 0L
    for (j in 0 until n) {
        tokenizer = StringTokenizer(jin.readLine())
        val party = tokenizer.nextToken().toInt() - 1
        if (party != 0) {
            val cost = tokenizer.nextToken().toLong()
            voters.add(Voter(party, cost))
            curr += cost
        }
    }
    voters.sortBy { it.cost }
    var party0 = n
    val parties = Array(m) { Stack<Long>() }
    val pq = PriorityQueue<Int>(compareByDescending { parties[it].size })
    pq.addAll(1 until m)
    var j = voters.lastIndex
    var answer = curr
    for (k in n - 1 downTo 1) {
        while (pq.isNotEmpty() && parties[pq.peek()].size == k) {
            val p = pq.remove()
            curr += parties[p].pop()
            pq.add(p)
            party0++
        }
        while (j >= 0 && party0 > k) {
            if (parties[voters[j].party].size < k - 1) {
                pq.remove(voters[j].party)
                parties[voters[j].party].push(voters[j].cost)
                pq.add(voters[j].party)
                party0--
                curr -= voters[j].cost
            }
            j--
        }
        answer = min(answer, curr)
    }
    println(answer)
}

data class Voter(val party: Int, val cost: Long)