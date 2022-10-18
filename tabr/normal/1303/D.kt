import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var (n,mm)=readlongs()
        var m=mm.toInt()
        var a=readints()
        var s=0L
        for(i in a){
            s+=i
        }
        if(s<n){
            cout(-1)
            continue
        }
        var t=IntArray(61)
        for(i in 0..m-1){
            var c=0
            while(a[i]%2==0){
                a[i]/=2
                c++
            }
            t[c]++
        }
        var ans=0
        var c=0L
        for(i in 0..60){
            c+=(1L shl i)*t[i]
            if((n and (1L shl i))!=0L){
                if(c<(1L shl i)){
                    c+=1L shl i
                    for(j in i+1..60){
                        if(t[j]!=0){
                            t[j]--
                            for(k in i..j-1){
                                ans++
                                t[k]++
                            }   
                            break
                        }
                    }
                }else{
                    c-=1L shl i
                }
            }
        }
        cout(ans)
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