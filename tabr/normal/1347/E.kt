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
        if(n<4){
            println(-1)
            continue
        }
        var a=listOf(3,1,4,2,5)
        var ans=IntArray(n)
        for(i in 0 until n){
            ans[i]=a[i%5]+(i/5)*5
        }
        if(n%5==1){
            ans[n-1]-=2
            ans[n-2]--
            ans[n-4]++
        }
        if(n%5==2){
            ans[n-1]++
            ans[n-2]-=3
            ans[n-3]-=3
            ans[n-4]+=4
        }
        if(n%5==3){
            ans[n-1]-=2
            ans[n-2]--
            ans[n-4]++
        }
        println(ans.joinToString(" "))
    }
}