import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val n = reader.readLine().toInt()
    val a = reader.readLine().split(" ").map { it.toInt() }

    val sum = IntArray(n + 1)
    for (i in 0 until n) {
        sum[i + 1] = sum[i] + a[i]
    }

    val nxt = mutableMapOf<Int, MutableList<Pair<Int, Int>>>()
    for (i in n - 1 downTo 0) {
        for (j in n downTo i + 1) {
            if (sum[j] - sum[i] !in nxt) {
                nxt[sum[j] - sum[i]] = mutableListOf(i to j)
            } else if (j <= nxt[sum[j] - sum[i]]!!.last().first) {
                nxt[sum[j] - sum[i]]!!.add(i to j)
            }
        }
    }

    var ans = mutableListOf<Pair<Int, Int>>()
    for ((_, list) in nxt) {
        if (list.size > ans.size) {
            ans = list
        }
    }

    writer.println(ans.size)
    for ((l, r) in ans) {
        writer.println("${l + 1} $r")
    }

    writer.close()
}