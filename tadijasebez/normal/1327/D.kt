import java.util.*
import java.math.*
import kotlin.math.*

fun readLn()=readLine()!!
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}
fun readLong()=readLn().toLong()
fun readLongs()=readLn().split(" ").map{it.toLong()}

val out=mutableListOf<String>()
fun printLine(s:String){out.add(s)}
fun output(){println(out.joinToString("\n"))}

fun main(){
    val t=readInt()
    repeat(t){
        var n=readInt()
        var p=readInts().map{it-1}.toIntArray()
        var c=readInts().toIntArray()
        var was=Array(n){false};var ans=n
        for(i in 0 until n)if(!was[i]){
            var j=i;var cyc=ArrayList<Int>()
            while(!was[j]){was[j]=true;cyc.add(c[j]);j=p[j]}
            for(sz in 1..cyc.size){
                if(cyc.size%sz==0){
                    for(k in 0 until sz){
                        var ok=true
                        for(ptr in k until cyc.size step sz){
                            if(cyc[ptr]!=cyc[k])ok=false
                        }
                        if(ok)ans=min(ans,sz)
                    }
                }
            }
        }
        printLine("$ans")
    }
    output()
}