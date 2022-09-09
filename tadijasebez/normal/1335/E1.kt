import java.util.*
import java.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts()  = readLn().split(" ").map{it.toInt()}
fun readLong() = readLn().toLong()
fun readLongs()  = readLn().split(" ").map{it.toLong()}

val out = mutableListOf<String>()
fun printLine(s: String) { out.add(s) }
fun output() { println(out.joinToString("\n")) }

fun main(){
    var t = readInt()
    for(tc in 1..t){
        var n = readInt()
        var a = readInts()
        var cnt = arrayOfNulls<IntArray>(201)
        for(j in 1..200){
            cnt[j] = IntArray(n+1)
            for(i in 0 until n){
                cnt[j]!![i+1] = cnt[j]!![i]
                if(a[i]==j)
                    cnt[j]!![i+1]++
            }
        }
        fun get(l:Int, r:Int):Int {
            var ans = 0
            for(j in 1..200)
                ans = Math.max(ans,cnt[j]!![r]-cnt[j]!![l-1])
            return ans
        }
        var idx = Array(201,{ArrayList<Int>()})
        for(i in 0 until n){
            idx[a[i]].add(i+1)
        }
        var ans = get(1,n)
        for(j in 1..200){
            var sz = idx[j].size
            for(i in 0 until sz/2)
                ans = Math.max(ans,(i+1)*2+get(idx[j][i]+1,idx[j][sz-i-1]-1))
        }
        printLine(ans.toString())
    }
    output()
}