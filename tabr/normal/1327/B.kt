import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

var mod=998244353

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var n=readint()
        var a=IntArray(n)
        var b=IntArray(n)
        for(i in 0..n-1){
            var c=readints()
            for(j in 1..c[0]){
                if(b[c[j]-1]==0){
                    a[i]=1
                    b[c[j]-1]=1
                    break
                }
            }
        }
        // println(b.joinToString(" "))
        var t=n-a.sum()
        if(t==0){
            cout("OPTIMAL")
        }else{
            cout("IMPROVE")
            for(i in 0..n-1){
                if(a[i]==0){
                    for(j in 0..n-1){
                        if(b[j]==0){
                            cout("${i+1} ${j+1}")
                            break
                        }
                    }
                    break
                }
            }
        }
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