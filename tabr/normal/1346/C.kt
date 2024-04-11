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
    var tt = readint()
    while (tt-- > 0) {
        var (n,k,x,y)=readlongs()
        var a=ArrayList(readlongs())
        a.sort()
        var go=k*n
        var ans=0L
        var sum=0L
        for(i in n.toInt()-1 downTo 0){
            sum+=a[i]
            if(a[i]>k){
                ans+=x
            }
        }
        var bns=y
        for(i in n.toInt()-1 downTo 0 ){
            if(sum>go){
                sum-=a[i]
                bns+=x
            }
        }
        ans=minOf(ans,bns)
        println(ans)
    }
}