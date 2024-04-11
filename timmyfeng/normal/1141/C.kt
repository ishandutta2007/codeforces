import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val n = reader.readLine().toInt()
    val diff = reader.readLine().split(" ").map { it.toInt() }

    val perm = LongArray(n)
    for (i in 0 until n - 1) {
        perm[i + 1] = perm[i] + diff[i]
    }

    val offset = perm.minOrNull()!!
    val nums = mutableSetOf<Long>()
    var ok = true
    for (i in 0 until n) {
        perm[i] -= offset
        ok = ok && perm[i] < n && perm[i] !in nums
        nums.add(perm[i])
    }

    if (ok) {
        for (i in perm) {
            writer.print("${i + 1} ")
        }
        writer.println()
    } else {
        writer.println(-1)
    }

    writer.close()
}