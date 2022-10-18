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
    var(n,k)=readints()
    var s=readln()
    var t=readln()
    if(t[0]==t[1]){
        var c=0
        for(i in 0..n-1){
            if(s[i]==t[0]){
                c++
            }
        }
        c=minOf(n,c+k)
        println(c*(c-1)/2)
        return
    }
    var dp = Array(n+2) { LongArray(k+2) { -100000000000000L } }
    dp[0][0]=0L
    for(i in 0..n-1){
        var ndp = Array(n+2) { LongArray(k+2) { -100000000000000L } }
        for(x in 0..i){
            for(y in 0..minOf(i,k)){
                ndp[x][y]=maxOf(ndp[x][y],dp[x][y])
                var ny=y
                if(s[i]!=t[0]){
                    ny++
                }
                ndp[x+1][ny]=maxOf(ndp[x+1][ny],dp[x][y])
                ny=y
                if(s[i]!=t[1]){
                    ny++
                }
                ndp[x][ny]=maxOf(ndp[x][ny],dp[x][y]+x)
            }
        }
        dp=ndp
        // for(x in 0..n){
            // println(dp[x].joinToString(" "));
        // }
        // println("")
    }
    var ans=0L
    for(i in 0..n){
        for(j in 0..k){
            ans=maxOf(ans,dp[i][j])
        }
    }
    println(ans)
}