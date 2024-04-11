import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
    var q = readInt()
    while (q > 0){
        q -= 1
        val s = readLn()
        val n = s.length
        var ck = true
        for (i in 0..n-1){
            if (s[i] != '='){
                ck = false
            }
        }
        if (ck == true){
            println('=')
            continue
        }
        ck = true
        for (i in 0..n-1){
            if (s[i] == '>'){
                ck = false
            }
        }
        if (ck == true){
            println('<')
            continue
        }
        ck = true
        for (i in 0..n-1){
            if (s[i] == '<'){
                ck = false
            }
        }
        if (ck == true){
            println('>')
            continue
        }
        println('?')
    }
}