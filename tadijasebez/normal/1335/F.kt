import java.util.*
import java.math.*

fun readLn()=readLine()!!
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}
fun readLong()=readLn().toLong()
fun readLongs()=readLn().split(" ").map{it.toLong()}

val out=mutableListOf<String>()
fun printLine(s: String){out.add(s)}
fun output(){println(out.joinToString("\n"))}

fun main(){
    val t=readInt()
    for(tc in 1..t){
        val (n,m)=readInts()
        val col=Array(n){readLn().toCharArray()}
        val dir=Array(n){readLn().toCharArray()}
        val go=Array(n*m){IntArray(21){-1}}
        for(i in 0 until n)
            for(j in 0 until m){
                val A = i*m+j
                when(dir[i][j]) {
                    'L' -> go[A][0]=A-1
                    'R' -> go[A][0]=A+1
                    'D' -> go[A][0]=A+m
                    'U' -> go[A][0]=A-m
                }
            }
        for(l in 1..20)
            for(i in 0 until n*m)
                go[i][l]=go[go[i][l-1]][l-1]
        val cnt=IntArray(n*m){0}
        val blk=IntArray(n*m){0}
        for(i in 0 until n*m) {
            cnt[go[i][20]]++
            if(col[i/m][i%m]=='0')
                blk[go[i][20]]++
        }
        var ans=0
        var blc=0
        for(i in 0 until n*m){
            if(cnt[i]>0)ans++
            if(blk[i]>0)blc++
        }
        printLine("$ans $blc")
    }
    output()
}