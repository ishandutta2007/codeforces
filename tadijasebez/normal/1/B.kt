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

fun make(_X:Int):String{
    var X=_X;var pw=26;var len=1
    while(X>pw){
        X-=pw;pw*=26;len++
    }
    X--
    var ans=""
    for(i in 0 until len){
        ans+=('A'+X%26)
        X/=26
    }
    ans=ans.reversed()
    return ans
}
fun take(str:String):Int{
    var len=str.length;var pw=26;var ans=0
    for(i in 1 until len){
        ans+=pw;pw*=26
    }
    var tmp=0
    for(i in 0 until len)tmp=tmp*26+(str[i]-'A')
    return ans+tmp+1
}
fun main(){
    val t=readInt()
    repeat(t){
        var str=readLn()
        var ok=false
        for(i in 1 until str.length){
            if(str[i-1].isDigit()&&str[i].isLetter())ok=true
        }
        var X=0;var Y=0
        if(ok){
            var tmp=str.split("C")
            X=tmp[0].substring(1).toInt()
            Y=tmp[1].toInt()
            printLine("${make(Y)}$X")
        }else{
            var cnt=0;while(str[cnt].isLetter())cnt++
            Y=str.substring(cnt).toInt()
            X=take(str.substring(0,cnt))
            printLine("R${Y}C$X")
        }
    }
    output()
}