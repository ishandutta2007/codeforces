import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val degree = IntArray(n + 1)
        val next = Array(n + 1) { mutableListOf<Int>() }
        for (a in 1..n) {
            val tokenizer = StringTokenizer(readLine()!!)
            repeat(tokenizer.nextToken().toInt()) {
                val b = tokenizer.nextToken().toInt()
                degree[a]++
                next[b].add(a)
            }
        }
        val disp = TreeSet<Int>()
        disp.addAll((1..n).filter { degree[it] == 0 })
        var answer = 0
        var rem = n
        while (rem > 0) {
            answer++
            if (disp.isEmpty()) {
                answer = -1
                break
            }
            var a = 0
            while (disp.isNotEmpty() && a < disp.last()) {
                a = disp.higher(a)!!
                disp.remove(a)
                rem--
                for (b in next[a]) {
                    degree[b]--
                    if (degree[b] == 0) {
                        disp.add(b)
                    }
                }
            }
        }
        println(answer)
    }
}