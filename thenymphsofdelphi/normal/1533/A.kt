import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
    val q = readInt()
    repeat(q){
        val (n, k) = readInts()
        var ans = 0
        for (i in 1..n){
            val (l, r) = readInts()
            if (l <= k && k <= r){
                ans = max(ans, r - k + 1)
            }
        }
        println(ans)
    }
}