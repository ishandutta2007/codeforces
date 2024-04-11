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
        var (a,b,x,y,n)=readlongs()
        if(a-x+b-y<=n){
            println(x*y)
            continue
        }
        var res:Long
        if(a-x>n){
            res=(a-n)*b
        }else{
            res=x*(b-(n-a+x))
        }
        if(b-y>n){
            res=minOf(res,(b-n)*a)
        }else{
            res=minOf(res,y*(a-(n-b+y)))
        }
        println(res)
    }
}