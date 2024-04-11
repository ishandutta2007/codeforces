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
        var w=readints()
        var ans=0
        var a=IntArray(151)
        for(i in 0..n-1){
            a[w[i]]++
        }
        for(i in 2..100){
            var s=0
            for(j in 1..50){
                if(j<i-j){
                    s+=minOf(a[j],a[i-j])
                }else if(j==i-j){
                    s+=a[j]/2
                }
            }
            ans=maxOf(ans,s)
        }
        println(ans)
    }
}