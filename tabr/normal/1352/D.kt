import java.util.*
fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() }
fun readlongs() = readstrings().map { it.toLong() }
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
    var tt=readint()
    while(tt-- > 0){
        var n=readint()
        var a=readints()
        var max=0
        var i=0
        var j=n-1
        var x=0
        var y=0
        var z=0
        while(i<=j){
            var cur=0
            z++
            while(cur<=max&&i<=j){
                cur+=a[i]
                i++
            }
            x+=cur
            max=cur
            if(i>j)break
            z++
            cur=0
            while(cur<=max&&i<=j){
                cur+=a[j]
                j--
            }
            y+=cur
            max=cur
        }
        println("$z $x $y")
    }
}