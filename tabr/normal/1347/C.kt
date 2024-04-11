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
        var n=readint()
        var s=1
        var ans=IntArray(6)
        var id=0
        while(n>0){
            if(n%10!=0){
                ans[id]=(n%10)*s
                id++
            }
            s*=10
            n/=10
        }
        println(id)
        for(i in 0 until id){
            print("${ans[i]} ")
        }
        print("\n")
    }
}