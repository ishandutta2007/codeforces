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
        var ans=0
        var ok=IntArray(n+1)
        var s=IntArray(n+1)
        for(i in 0 until n){
            s[i+1]=s[i]+a[i]
            for(j in 0 until i){
                if(s[i+1]-s[j]>n)continue
                ok[s[i+1]-s[j]]=1
            }
        }
        for(i in 0 until n){
            ans+=ok[a[i]]
        }
        println(ans)
    }
}