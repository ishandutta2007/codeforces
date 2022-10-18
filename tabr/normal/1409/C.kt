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
        var (n,x,y)=readints()
        var ans=2000000000
        var a0=-1
        var d=-1
        for(i in 0..n-2){
            if((y-x)%(i+1)==0){
                var e=(y-x)/(i+1)
                var b0=x
                while((b0>e) and ((b0-e)+e*(n-1)>=y)){
                    b0-=e
                }
                if(b0+e*(n-1)<ans){
                    ans=b0+e*(n-1)
                    d=e
                    a0=b0
                }
            }
        }
        for(i in 0..n-1){
            print(" ${a0+d*i}")
        }
        print("\n")
    }
}