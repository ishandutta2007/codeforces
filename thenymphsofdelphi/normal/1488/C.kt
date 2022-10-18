import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(args: Array<String>) {
    val q = readInt()
    repeat(q){
        var (n, x, y) = readInts()
        var ans = 1000000000
        if (x > y){
            var ccccc = x
            x = y
            y = ccccc
        }
        for (i in x..y-1){
            ans = min(ans, max(i - 1 + min(x - 1, i - x), n - i - 1 + min(y - i - 1, n - y)))
        }
        println(ans)
    }
}