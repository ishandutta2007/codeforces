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
        var(n,k)=readlongs()
        var i=1L
        var ans=n
        while(i*i<=n){
            if(n%i!=0L){
                i++
                continue
            }
            if(i<=k){
                ans=minOf(ans,n/i)
            }
            if(n/i<=k){
                ans=minOf(ans,i)
            }
            i++
        }
        println(ans)
    }
}

// kotlin sol.jar<in>out