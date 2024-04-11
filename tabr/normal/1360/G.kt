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
        var (n,m,a,b)=readints()
        if(a*n!=b*m){
            println("NO")
            continue
        }
        var g = gcd(a,b)
        var s=a/g
        var t=b/g
        var ans = Array(n) { IntArray(m) { 0 } }
        var z=n/t
        for(dif in 0..z){ 
            if(dif==z){
                println("NO")
                break
            }   
            for(i in 0..n-1){
                for(j in 0..m-1){
                    if((i / t + z + dif) % z ==(j / s)){
                        ans[i][j]=1
                    }
                }
            }
            var an="YES"
            for(i in 0..n-1){
                var x=0
                for(j in 0..m-1){
                    x+=ans[i][j]
                }
                if(x!=a){
                    an="NO"
                }
            }
            for(j in 0..m-1){
                var x=0
                for(i in 0..n-1){
                    x+=ans[i][j]
                }
                if(x!=b){
                    an="NO"
                }
            }
            if(an=="YES"){
                println("YES")
                for(i in 0..n-1){
                    println(ans[i].joinToString(""))
                }
                break
            }
        }
    }
}

fun gcd(a: Int, b: Int): Int{
    if(b == 0) return a
    return gcd(b, a%b)
}

// kotlin sol.jar<in>out