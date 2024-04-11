import java.io.*
import java.util.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    for (t in 0 until reader.readLine().toInt()) {
        val n = reader.readLine().toInt()
        val q = reader.readLine().split(" ").map { it.toInt() }

        val ansMin = q.toIntArray()
        val ansMax = q.toIntArray()
        val setMin = TreeSet<Int>()
        val setMax = TreeSet<Int>()

        var prev = 0
        for (i in 0 until n) {
            if (q[i] == prev) {
                ansMin[i] = setMin.first()
                setMin.remove(ansMin[i])
                ansMax[i] = setMax.last()
                setMax.remove(ansMax[i])
            } else {
                for (j in prev + 1 until q[i]) {
                    setMin.add(j)
                    setMax.add(j)
                }
                prev = q[i]
            }
        }

        writer.println(ansMin.joinToString(" "))
        writer.println(ansMax.joinToString(" "))
    }

    writer.close()
}