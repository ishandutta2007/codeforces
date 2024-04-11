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
    while(tt-->0){
        var n=readint()
        var a=readints()
        var mn=a.min()
        var mx=a.max()
        if(mn==mx){
            println("NO")
            continue
        }
        println("YES")
        var l=ArrayList<Int>()
        var r=ArrayList<Int>()
        var m=ArrayList<Int>()
        for(i in 0..n-1){
            if(a[i]==mn){
                l.add(i+1)
            }else if(a[i]==mx){
                r.add(i+1)
            }else{
                m.add(i+1)
            }
        }
        println("${l[0]} ${r[0]}")
        for(i in m){
            println("${l[0]} ${i}")
        }
        for(i in r){
            if(i!=r[0]){
                println("${l[0]} ${i}")
            }
        }
        for(i in l){
            if(i!=l[0]){
                println("${r[0]} ${i}")
            }
        }
    }
}