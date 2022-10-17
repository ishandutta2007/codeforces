import java.util.*

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}

fun main() {
    var t = readi()
    while(t-- > 0) {
        var (a, b) = readii()
        println(a + b)
    }
}