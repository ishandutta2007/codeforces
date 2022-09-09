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
        var (h,c,t)=readInts()
        var dif=h-c
        if(t*2<=h+c)printLine("2")
        else{
            var bot=0;var top=1e9.toInt();var idx=0
            while(top>=bot){
                var mid:Long=((top+bot)/2).toLong()
                if((mid*2+1)*(t-c)>(mid+1)*dif){
                    top=mid.toInt()-1;idx=mid.toInt()
                }else bot=mid.toInt()+1
            }
            if(idx==0)printLine("${idx*2+1}")
            else{
                var A=(t-c)*(idx*2+1).toLong()-dif*(idx+1).toLong()
                var B=dif*(idx).toLong()-(t-c)*(idx*2-1).toLong()
                if(A*(2*idx-1)<B*(2*idx+1))printLine("${2*idx+1}")
                else printLine("${2*idx-1}")
            }
        }
    }
    output()
}