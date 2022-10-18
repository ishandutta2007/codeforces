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
        var n=readint()
        var b=readints()
        var a=b.toMutableList()
        a.sort()
        var nodd=0
        var neven=0
        var np=0
        for(i in 0..n-1){
            if(a[i]%2==0){
                neven++
            }else{
                nodd++
            }
            if(i!=n-1){
                if(a[i]+1==a[i+1]){
                    np++
                }
            }
        }
        var ans="NO"
        if(nodd%2==0 && neven%2==0){
            ans="YES"
        }
        if(nodd%2==1 && neven%2==1 && np>0){
            ans="YES"
        }
        println(ans)
    }
}

// kotlin sol.jar<in>out