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
        var(n,s)=readlongs()
        var m=1000000000000000000L
        var ans=m
        while(m!=0L){
            var x=(n+m-1)/m*m
            var sum=0L
            var y=1000000000000000000L
            while(y!=0L){
                sum+=x/y%10L
                y/=10L
            }
            if(s>=sum){
                ans=minOf(ans,x)
            }else{
                break
            }
            m/=10L
        }
        println(ans-n)
    }
}