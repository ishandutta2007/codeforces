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
        val n = readInt()
        val a = readInts()
        var ans = false
        for (i in 1..n-1){
            if (a[i] % 2 == a[i - 1] % 2){
                ans = true
            }
        }
        if (ans == true){
            println("YES")
        }
        else{
            println("NO")
        }
    }
}