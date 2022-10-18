import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
    val (n, m) = readInts()
    val stt = mutableSetOf<String>()
    repeat(n){
        val s = readLn()
        stt.add(s)
    }
    val q = readInt()
    repeat(q){
        val s = readLn()
        var ans = 0
        for (i in 0..m){
            if (i >= 1 && s[i] == s[i - 1]){
                continue
            }
            if (stt.contains(s.substring(0, i) + s.substring(i + 1, m + 1))){
                ans++
            }
        }
        println(ans)
    }
}