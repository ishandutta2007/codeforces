import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val genres = jin.readLine().split(" ").map { it.toInt() }
        val right = IntArray(n + 1) { j -> (j + 1) % n }
        val treeSet = TreeSet<Int>()
        treeSet.addAll((0 until n).filter { j -> gcd(genres[j], genres[(j + 1) % n]) == 1 })
        var j = -1
        val answer = mutableListOf<Int>()
        while (treeSet.isNotEmpty()) {
            j = treeSet.higher(j) ?: treeSet.first()!!
            answer.add(right[j] + 1)
            treeSet.remove(right[j])
            right[j] = right[right[j]]
            if (gcd(genres[j], genres[right[j]]) != 1) {
                treeSet.remove(j)
            }
        }
        out.appendln(answer.size)
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)