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
    var t=readint()
    while(t-- > 0){
        var (n,k)=readints()
        var ans = IntArray(k)
        if(n%2==k%2&&n>=k){
            println("YES")
            for(i in 1 until k)ans[i]=1
            ans[0]=n-k+1
            println(ans.joinToString(" "))
        }else if(n%2==0&&n>=k*2){
            println("YES")
            for(i in 1 until k)ans[i]=2
            ans[0]=n-(k-1)*2
            println(ans.joinToString(" "))
        }else{
            println("NO")
        }
    }
}