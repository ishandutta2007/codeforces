import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val front = IntArray(n)
    var tokenizer = StringTokenizer(readLine()!!)
    val a = LongArray(n) { tokenizer.nextToken().toLong() }
    tokenizer = StringTokenizer(readLine()!!)
    val b = LongArray(n) { tokenizer.nextToken().toLong()}
    val q = LinkedList<Int>()
    for (j in 0 until n) {
        for (k in 0 until n) {
            if (k != j) {
                if (a[j] and a[k] == a[j]) {
                    front[j]++
                }
            }
        }
        if (front[j] == 0) {
            q.add(j)
        }
    }
    while (!q.isEmpty()) {
        val j = q.removeFirst()
        for (k in 0 until n) {
            if (k != j && a[k] and a[j] == a[k]) {
                front[k]--
                if (front[k] == 0) {
                    q.add(k)
                }
            }
        }
    }
    var amt = 0
    var answer = 0L
    for (j in 0 until n) {
        if (front[j] != 0) {
            amt++
            answer += b[j]
        }
    }
    println(answer)
}