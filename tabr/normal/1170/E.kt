fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main(){
    var (n,m)=readints()
    var a=readints()
    var s=IntArray(n+1)
    for(i in 0 until n){
        s[i+1]=s[i]+a[i]
    }
    var q=readint()
    while(q-- > 0){
        val w = readstrings().drop(1).map{it.toInt()}
        var c=w.size
        var x=IntArray(c+1)
        x[0]=w[0]-1
        x[c]=m-w[c-1]
        for(i in 1 until c){
            x[i]=w[i]-w[i-1]-1
        }
        var ans="NO"
        var j=0
        for(t in x){
            var lo=j
            var hi=n+1
            while(hi-lo>1){
                var mid=(hi+lo)/2
                var sum=s[mid]-s[j]
                if(sum<=t){
                    lo=mid
                }else{
                    hi=mid
                }
            }
            j=lo
            if(j==n){
                break
            }
        }
        if(j==n){
            ans="YES"
        }
        println(ans)
    }
}