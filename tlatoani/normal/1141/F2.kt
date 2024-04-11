import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val array = jin.readLine().split(" ").map { it.toInt() }
    val same = mutableMapOf<Int, MutableList<Int>>()
    for (right in 1..n) {
        var curr = 0
        for (left in right downTo 1) {
            curr += array[left - 1]
            val blocks = same.computeIfAbsent(curr) { ArrayList(1) }
            if (blocks.isEmpty() || blocks.last() < left) {
                blocks.add(left)
                blocks.add(right)
            }
        }
    }
    val answer = same.values.maxBy { it.size }!!
    val out = StringBuilder()
    out.appendln(answer.size / 2)
    for (j in answer.indices) {
        out.append(answer[j]).append(if (j % 2 == 0) ' ' else '\n')
    }
    print(out)
}