import java.util.*
fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() }
fun readlongs() = readstrings().map { it.toLong() }
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var(n,m)=readints()
        var a=LongArray(n)
        for(i in 0..n-1){
            var s=readln()
            var l=0L
            for(j in 0..m-1){
                if(s[j]=='1'){
                    l+= 1L shl (m-1-j)
                }
            }
            a[i]=l
        }
        var z = ((1L shl m)-n.toLong()- 1L)/2L
        var lo=-1L
        var hi=1L shl m
        while(hi-lo>1L){
            var mid=(hi+lo)/2L
            var cnt=mid+1L
            for(i in 0..n-1){
                if(a[i]<=mid){
                    cnt--
                }
            }
            if(cnt<=z){
                lo=mid
            }else{
                hi=mid
            }
        }
        var ans=""
        lo=hi
        for(i in m-1 downTo 0){
            if((lo and (1L shl i)) != 0L){
                ans+='1'
            }else{
                ans+='0'
            }
        }
        println(ans)
    }
}

// kotlin sol.jar<in>out