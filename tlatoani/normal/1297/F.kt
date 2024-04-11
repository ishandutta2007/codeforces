import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var tokenizer = StringTokenizer(readLine()!!)
        val n = tokenizer.nextToken().toInt()
        val m = tokenizer.nextToken().toInt()
        val a = IntArray(n)
        val b = IntArray(n)
        for (j in 0 until n) {
            tokenizer = StringTokenizer(readLine()!!)
            a[j] = tokenizer.nextToken().toInt()
            b[j] = tokenizer.nextToken().toInt()
        }
        val js = Array(n) { it }
        js.sortBy { a[it] }
        fun find(d: Int): IntArray? {
            val res = IntArray(n)
            var t = 0
            var x = 0
            val pq = PriorityQueue<Int>(compareBy { b[it] })
            while (x < n || pq.isNotEmpty()) {
                if (pq.isEmpty()) {
                    t = a[js[x]]
                }
                while (x < n && a[js[x]] == t) {
                    pq.add(js[x])
                    x++
                }
                if (b[pq.peek()] + d < t) {
                    return null
                }
                for (s in 1..m) {
                    if (pq.isEmpty()) {
                        break
                    }
                    res[pq.poll()] = t
                }
                t++
            }
            return res
        }
        var upper = n + 1
        var lower = 0
        while (upper > lower) {
            val mid = (upper + lower) / 2
            if (find(mid) == null) {
                lower = mid + 1
            } else {
                upper = mid
            }
        }
        println(upper)
        println(find(upper)!!.joinToString(" "))
    }
}