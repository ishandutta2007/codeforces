import java.util.*
import kotlin.math.*

fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun readdoubles() = ArrayList(readstrings().map { it.toDouble() })

fun main() {
    var tt=readint()
    while(tt-- > 0){
        var(nn,k)=readlongs()
        var n=nn.toInt()
        var s=readln()
        var z=0L
        var ones=0L
        var t = CharArray(n)
        var ok = false
        for(i in 0..n-1){
            if(s[i]=='0'){
                if(ones<=k){
                    k-=ones
                    z++
                }else{
                    ok=true
                    for(j in 0..z.toInt()-1){
                        t[j]='0'
                    }
                    for(j in z.toInt()..z.toInt()+ones.toInt()){
                        t[j]='1'
                    }
                    t[i-k.toInt()]='0'
                    for(j in i+1..n-1){
                        t[j]=s[j]
                    }
                    break
                }
            }else{
                ones++
            }
        }
        if(!ok){
            for(i in 0..z.toInt()-1){
                t[i]='0'
            }
            for(i in z.toInt()..n-1){
                t[i]='1'
            }
        }
        println(t.joinToString(""))
    }
}