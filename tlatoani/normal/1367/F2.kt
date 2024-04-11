import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val array = jin.readLine().split(" ").map { it.toInt() }
        val spots = (0 until n).sortedWith(compareBy({ array[it] }, { -it }))
        val treeSet = TreeSet<Int>()
        var j = 0
        while (j < n) {
            val lower = treeSet.lower(spots[j])
            val higher = treeSet.higher(spots[j])
            if ((lower != null && array[lower] > array[spots[j]]) || (higher != null && array[higher] < array[spots[j]])) {
                break
            }
            treeSet.add(spots[j])
            j++
        }
        var largest = treeSet.size
        for (k in 0 until n) {
            treeSet.remove(spots[k])
            while (j < n) {
                val lower = treeSet.lower(spots[j])
                val higher = treeSet.higher(spots[j])
                if ((lower != null && array[lower] > array[spots[j]]) || (higher != null && array[higher] < array[spots[j]])) {
                    break
                }
                treeSet.add(spots[j])
                j++
            }
            largest = max(largest, treeSet.size)
        }
        out.appendln(n - largest)
    }
    print(out)
}