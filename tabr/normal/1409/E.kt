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
        var(n,k)=readints()
        var x=ArrayList(readints())
        x.sort()
        x.add(-1)
        readLine()
        var a=IntArray(n+1)
        var b=IntArray(n+1)
        var j=0
        for(i in 0..n-1){
            while((j!=n) and (x[j]<=x[i]+k)){
                j++
            }
            a[i]=j-i
        }
        var ans=0
        for(i in 0..n-1){
            b[n-1-i]=maxOf(b[n-i],a[n-1-i])
        }
        // println(a.joinToString(" "))
        // println(b.joinToString(" "))
        j=0
        for(i in 0..n-1){
            while((j!=n) and (x[j]<=x[i]+k)){
                j++
            }
            ans=maxOf(ans,a[i]+b[j])
        }
        println(ans)
    }
}