import java.util.*

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}

fun main() {
    var n = readi()
    var a = readii()
    a = a.sortedBy { it }
    var ans: Long = 0
    for (i in 0..n-1 step 2) {
        ans += a[i+1] - a[i]
    }
    println(ans)
}