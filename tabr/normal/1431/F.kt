import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var(n,k,x)=readints()
    var a=readlongs()
    var hi=1e12.toLong()
    var lo=-1L
    while(hi-lo>1L){
        var mid=(hi+lo)/2
        var d=0
        val pq = PriorityQueue<Long>(compareBy { -it })
        var sum=0L
        var cnt=0
        for(i in 0..n-1){
            cnt++
            sum+=a[i]
            pq.add(a[i])
            if(cnt==x){
                if(sum<=mid){
                    pq.clear()
                    sum=0L
                    cnt=0
                }else{
                    cnt--
                    sum-=pq.peek()
                    pq.poll()
                    d++
                }
            }
        }
        while(!pq.isEmpty() && sum>mid){
            sum-=pq.peek()
            pq.poll()
            d++
        }
        if(d<=k){
            hi=mid
        }else{
            lo=mid
        }
    }
    println(hi)
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