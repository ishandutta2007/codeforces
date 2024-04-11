import java.util.PriorityQueue
fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }
 
fun main() {
	var (n,a,b,k)=readints()
    var r=readints()
    var x=IntArray(1000010)
    for(i in r){
        x[i]++
    }
    var ans=0
    if(a>=b){
        for(i in 1..1000000){
        	if(i*k>1000000)continue
            var t = minOf(x[i]/a, x[i*k]/b)
            ans+=t
            x[i]-=a*t
            x[i*k]-=b*t
    	}
    }else{
        for(i in 1000000 downTo 1){
        	if(i*k>1000000)continue
            var t = minOf(x[i]/a, x[i*k]/b)
            ans+=t
            x[i]-=a*t
            x[i*k]-=b*t
    	}
    }
    println(ans)
}