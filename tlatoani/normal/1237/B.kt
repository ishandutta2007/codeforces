import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val entering = TreeMap<Int, Int>()
    val exiting = IntArray(n + 1)
    val inTime = IntArray(n + 1)
    val outTime = IntArray(n + 1)
    for (t in 1..n) {
        val a = jin.nextInt()
        entering[t] = a
        inTime[a] = t
    }
    for (t in 1..n) {
        val b = jin.nextInt()
        exiting[t] = b
        outTime[b] = t
    }
    var answer = 0
    for (t in 1..n) {
        if (exiting[t] != entering.firstEntry().value) {
            answer++
        }
        entering.remove(inTime[exiting[t]])
    }
    println(answer)
}