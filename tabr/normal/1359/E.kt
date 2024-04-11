import java.util.*
fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() }
fun readlongs() = readstrings().map { it.toLong() }
fun readdoubles() = readstrings().map { it.toDouble() }

var mod=998244353L

fun pw(a:Long,b:Long):Long{
    var c=b
    var d=a
    var res=1L
    while(c>0){
        if((c and 1L)!=0L){
            res*=d
            res%=mod
        }
        d*=d
        d%=mod
        c/=2
    }
    return res
}

fun inv(a:Long):Long{
    return pw(a,mod-2L)
}

fun main() {
    var tt = 1
    var f=LongArray(500010){1L}
    for(i in 2..500000){
        f[i]=f[i-1]*i.toLong()%mod
    }
    while (tt-- > 0) {
        var (n,k)=readints()
        var ans=0L
        for(i in 1..n-k+1){
            var cnt=n/i
            if(cnt<k){
                continue
            }
            var sum=f[cnt-1]*inv(f[k-1])%mod
            sum=inv(f[cnt-k])*sum%mod
            ans+=sum
            ans%=mod
        }
        println(ans)
    }
}