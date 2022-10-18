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
    var(n,m,q)=readints()
    var a=Array(n){LongArray(m)}
    var tate=LongArray(n)
    var yoko=LongArray(m)
    for(i in 0..n-1){
        var b=readlongs()
        for(j in 0..m-1){
            a[i][j]=b[j]
            tate[i]+=b[j]
            yoko[j]+=b[j]
        }
    }
    var ans=LongArray(q+1)
    for(tt in 0..q){
        if(tt!=0){
            var(x,y,z)=readints()
            x--
            y--
            tate[x]+=z.toLong()-a[x][y]
            yoko[y]+=z.toLong()-a[x][y]
            a[x][y]=z.toLong()
        }
        var rtate=LongArray(n)
        var ltate=LongArray(n)
        var rall=0L
        for(i in n-1 downTo 1){
            rtate[i]=tate[i]
            if(i!=n-1){
                rtate[i]+=rtate[i+1]
            }
            rall+=rtate[i]
        }
        for(i in 0..n-1){
            ltate[i]=tate[i]
            if(i!=0){
                ltate[i]+=ltate[i-1]
            }
        }
        var tatemin=rall // i=0
        var lall=0L
        for(i in 1..n-2){
            rall-=rtate[i]
            lall+=ltate[i-1]
            tatemin=minOf(tatemin,lall+rall)
        }
        if(n>1)tatemin=minOf(tatemin,lall+ltate[n-2])

        var ryoko=LongArray(m)
        var lyoko=LongArray(m)
        rall=0L
        for(i in m-1 downTo 1){
            ryoko[i]=yoko[i]
            if(i!=m-1){
                ryoko[i]+=ryoko[i+1]
            }
            rall+=ryoko[i]
        }
        for(i in 0..m-1){
            lyoko[i]=yoko[i]
            if(i!=0){
                lyoko[i]+=lyoko[i-1]
            }
        }
        var yokomin=rall // i=0
        lall=0L
        for(i in 1..m-2){
            rall-=ryoko[i]
            lall+=lyoko[i-1]
            yokomin=minOf(yokomin,lall+rall)
        }
        if(m>1)yokomin=minOf(yokomin,lall+lyoko[m-2])
        
        ans[tt]=tatemin+yokomin
    }
    println(ans.joinToString(" "))
}