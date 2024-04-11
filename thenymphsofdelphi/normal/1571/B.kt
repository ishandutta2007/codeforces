import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
    var q = readInt()
    repeat(q){
        val n = readInt()
        val (a, va) = readInts()
        val (c, vc) = readInts()
        val b = readInt()
        var ans = max(va, vc - (c - b))
        println(ans)
    }
}