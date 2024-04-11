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
        val (n, k) = readInts()
        val (s) = readStrings()
        var x = 0
        var y = n / 2
        var t = 0
        for (c in s){
            if (c == '('){
                t = t + 1
            }
            else{
                t = t - 1
            }
            if (t == 0){
                x = x + 1
                y = y - 1
            }
        }
        var ans = x + min(y, k)
        println(ans)
    }
}