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

fun TreeMap<Char,Int>.add(i:Char,x:Int){
    set(i,getOrDefault(i,0)+x)
}
fun main(){
    var a=Array(3){readLn().toCharArray()}
    var cnt=TreeMap<Char,Int>()
    for(j in 0..2)for(i in a[j])cnt.add(i,1)
    var o=cnt.getOrDefault('0',0)
    var x=cnt.getOrDefault('X',0)
    if(o>x || x>o+1)printLine("illegal")
    else{
        fun win(c:Char):Boolean{
            for(j in 0..2)if(a[j][0]==c&&a[j][1]==c&&a[j][2]==c)return true
            for(j in 0..2)if(a[0][j]==c&&a[1][j]==c&&a[2][j]==c)return true
            if(a[0][0]==c&&a[1][1]==c&&a[2][2]==c)return true
            if(a[2][0]==c&&a[1][1]==c&&a[0][2]==c)return true
            return false
        }
        if(win('X')&&win('0'))printLine("illegal")
        else{
            if(win('X')){
                var ok=false
                for(i in 0..2)for(j in 0..2)if(a[i][j]=='X'){
                    a[i][j]='.'
                    if(!win('X'))ok=true
                    a[i][j]='X'
                }
                if(ok&&x==o+1)printLine("the first player won")
                else printLine("illegal")
            }else if(win('0')){
                var ok=false
                for(i in 0..2)for(j in 0..2)if(a[i][j]=='0'){
                    a[i][j]='.'
                    if(!win('0'))ok=true
                    a[i][j]='0'
                }
                if(ok&&x==o)printLine("the second player won")
                else printLine("illegal")
            }else{
                if(x+o==9)printLine("draw")
                else if(x>o)printLine("second")
                else printLine("first")
            }
        }
    }
    output()
}