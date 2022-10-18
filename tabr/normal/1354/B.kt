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
    var tt = readint()
    while (tt-- > 0) {
        var s=readln()
        var n=s.length
        var al=IntArray(n){-1}
        var ar=IntArray(n){n}
        var bl=IntArray(n){-1}
        var br=IntArray(n){n}
        for(i in 0..n-1){
            if(i!=0){
                al[i]=al[i-1]
                bl[i]=bl[i-1]
            }
            if(s[i]=='2'){
                al[i]=i
            }else if(s[i]=='3'){
                bl[i]=i
            }
        }
        for(i in n-1 downTo 0){
            if(i!=n-1){
                ar[i]=ar[i+1]
                br[i]=br[i+1]
            }
            if(s[i]=='2'){
                ar[i]=i
            }else if(s[i]=='3'){
                br[i]=i
            }
        }
        var ans=1e9.toInt()
        for(i in 0..n-1){
            if(s[i]!='1'){
                continue
            }
            if(al[i]!=-1){
                if(bl[i]!=-1){
                    ans=minOf(ans,maxOf(i-al[i]+1,i-bl[i]+1))
                }
                if(br[i]!=n){
                    ans=minOf(ans,br[i]-al[i]+1)
                }
            }
            if(ar[i]!=n){
                if(bl[i]!=-1){
                    ans=minOf(ans,ar[i]-bl[i]+1)
                }
                if(br[i]!=n){
                    ans=minOf(ans,maxOf(br[i]-i+1,ar[i]-i+1))
                }
            }
        }
        if(ans==1e9.toInt()){
            println("0")
        }else{
            println("$ans")
        }
    }
}