import java.util.*

fun main() {
    val fibonacci = mutableListOf(0, 1)
    while (fibonacci.last() < 1000000000) {
        fibonacci.add(fibonacci[fibonacci.size - 2] + fibonacci.last())
    }
    fibonacci.removeAt(fibonacci.lastIndex)
    val fibSums = IntArray(fibonacci.size)
    for (j in 1 until fibonacci.size) {
        fibSums[j] = fibSums[j - 1] + fibonacci[j]
    }
    repeat(readLine()!!.toInt()) {
        readLine()
        val freqs = readLine()!!.split(" ").map { it.toInt() }
        if (freqs.map { it.toLong() }.sum() > fibSums.last().toLong()) {
            println("no")
        } else {
            if (freqs.sum() in fibSums) {
                if (freqs.sum() == 1) {
                    println("yEs")
                } else {
                    var j = fibSums.indexOf(freqs.sum())
                    val pq = PriorityQueue<Pair<Int, Int>>(compareBy { -it.second })
                    for ((k, x) in freqs.withIndex()) {
                        pq.add(Pair(k, x))
                    }
                    var answer = "YeS"
                    var prev = -1
                    while (j > 2) {
                        val (k, x) = pq.remove()
                        if (prev == k) {
                            answer = "No"
                            break
                        }
                        prev = k
                        if (x < fibonacci[j]) {
                            answer = "No"
                            break
                        }
                        pq.add(Pair(k, x - fibonacci[j]))
                        j--
                    }
                    if (answer == "YeS" && pq.peek().second == 2) {
                        answer = "No"
                    }
                    println(answer)
                }
            } else {
                println("nO")
            }
        }
    }
}