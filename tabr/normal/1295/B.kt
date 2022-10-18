import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var (n,x)=readints()
        var s=readln()
        var t=0
        var a=TreeMap<Int,Int>()
        for(i in 0..n-1){
            if(s[i]=='0'){
                t++
            }else{
                t--
            }
            a[t]=1+(a[t]?:0)
        }
        if(t==0){
            a[0]=1
            if((a[x]?:0)!=0){
                cout(-1)
            }else{
                cout(0)
            }
        }else if(t>0){
            var ans=0
            if(x==0){
                ans++
            }
            for((k,v)in a){
                if((k%t+t)%t==(x%t+t)%t&&x>=k){
                    ans+=v
                }
            }
            cout(ans)
        }else{
            var ans=0
            if(x==0){
                ans++
            }
            t=-t
            for((k,v)in a){
                if((k%t+t)%t==(x%t+t)%t&&x<=k){
                    ans+=v
                }
            }
            cout(ans)
        }
    }
    print(output)
}

fun readln() = input.readLine()
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun cout(s: String) = output.appendln(s)
fun cout(s: Int) = output.appendln(s.toString())
fun cout(s: Long) = output.appendln(s.toString())