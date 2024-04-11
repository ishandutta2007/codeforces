import java.util.*

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val sociability = (listOf(0) + readLine()!!.split(" ").map { it.toInt() }).toIntArray()
        val pq = PriorityQueue<Int>(compareByDescending { sociability[it] })
        pq.addAll(1..n)
        val builder = StringBuilder()
        while (true) {
            val a = pq.remove()
            val b = pq.remove()
            if (sociability[b] == 0) {
                break
            }
            builder.appendln("$a $b")
            sociability[a]--
            sociability[b]--
            pq.add(a)
            pq.add(b)
        }
        out.appendln(builder.count { it == '\n' })
        out.append(builder)
    }
    print(out)
}