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
        var (n,m,k)=readints()
        for(i in 1..2*k){
            readln()
        }
        var a=""
        for(i in 1..n-1){
            a+="U"
        }
        for(i in 1..m-1){
            a+="L"
        }
        var d=""
        var u=""
        for(i in 1..n-1){
            d+="D"
            u+="U"
        }
        for(i in 0..m-1){
            if(i%2==0){
                a+=d
            }else{
                a+=u
            }
            if(i!=m-1){
                a+="R"
            }
        }
        cout(a.length)
        cout(a)
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