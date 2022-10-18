fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main(){
    var(n,m,k)=readints()
    var aa=readlongs()
    var a=aa.sorted()
    var s=LongArray(n+1)
    for(i in 0 until n){
        s[i+1]=s[i]+a[i]
    }
    var ans=(1e18).toLong()
    for(i in 0..n-m){
        var lo=i
        var hi=i+(m+1)/2
        while(hi-lo>1){
            var mid=(hi+lo)/2
            var tmp=a[mid]*(mid-i+1).toLong()-(s[mid+1]-s[i])
            if(tmp<=k){
                lo=mid
            }else{
                hi=mid
            }
        }
        var sum=a[lo]*(lo-i+1).toLong()-(s[lo+1]-s[i])
        sum+=s[i+m]-s[lo]-a[lo]*(i+m-lo).toLong()
        if(lo+1!=i+(m+1)/2){
            var cnt=a[lo]*(lo-i+1).toLong()-(s[lo+1]-s[i])
            var add=lo-i+1
            var dif=add-(i+m-lo-1)
            var x=(k-cnt)/add
            sum+=x*dif
        }
        ans=minOf(ans,sum)
    }
    println(ans)
}