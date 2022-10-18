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
        var (n,k1,k2)=readints()
        var s=readln()
        var ans=0
        var lst=-10
        for(i in 0..n-1){
            if(s[i]=='1'){
                if(lst!=i-1){
                    ans+=k1
                    lst=i
                }else{
                    ans+=minOf(k1,k2-k1)
                }
            }
        }
        println(ans)
    }
}