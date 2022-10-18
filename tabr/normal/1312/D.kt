import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

var mod=998244353

fun main() {
    var tt = 1
    while (tt-- > 0) {
        var (n,m)=readints()
        if(n==2){
            cout(0)
            continue
        }
        var z=pow(2,n-3)
        var a=0
        var x=IntArray(m+10){1}
        for(i in 2..m+9){
            x[i]=mul(x[i-1],i)
        }
        var c=mul(x[m-1],inv(mul(x[n-2],x[m-n+1])))
        for(i in 1..m){
            var d=0
            if(m-i-n+2>=0){
                d=mul(x[m-i],inv(mul(x[n-2],x[m-i-n+2])))
            }
            a=add(a,sub(c,d))
        }
        cout(mul(a,z))
    }
    print(output)
}

fun readln() = input.readLine()
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun cout(s: String) = output.appendln(s)
fun cout(s: Int) = output.appendln(s.toString())
fun cout(s: Long) = output.appendln(s.toString())

fun add(a: Int, b: Int): Int {
    return (a + b) % mod
}

fun sub(a: Int, b: Int): Int {
    return ((a - b) % mod + mod) % mod
}

fun mul(a: Int, b: Int): Int {
    return (1L * a * b % mod).toInt()
}

fun inv(a: Int): Int {
    return pow(a, mod - 2)
}

fun pow(_a: Int, _b: Int): Int {
    var a = _a
    var b = _b
    var res = 1
    while(b > 0) {
        if((b and 1) != 0) {
            res = mul(res, a)
        }
        a = mul(a, a)
        b /= 2
    }
    return res
}