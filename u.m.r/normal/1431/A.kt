import java.io.*
import java.util.*

val MOD = 1000000007
val SZ = 1 shl 18
val INF = (1e18).toLong()
 
fun add(a: Int, b: Int) = (a + b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()
fun min(a: Double, b: Double) = if (a < b) a else b
fun max(a: Double, b: Double) = if (a > b) a else b
fun min(a: Long, b: Long) = if (a < b) a else b
fun max(a: Long, b: Long) = if (a > b) a else b
fun max(a: Int, b: Int) = if (a > b) a else b
 
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun printInts(a: Array<Int>) = println(a.joinToString("\n")) 
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }

fun gcd(a: Int, b: Int): Int {
    return if (a == 0) b else gcd(b % a,a)
}

var zero = 0.toLong();
var one = 1.toLong();
var two = 2.toLong();
var three = 3.toLong();
var four = 4.toLong();
var five = 5.toLong();
fun powmod(aa: Long, bb: Long, mod: Long): Long {
    var ret = one
    var a = aa
    var b = bb
    while (b > zero) {
        if (b % two == one) {
            ret = ret * a % mod
        }
        a = a * a % mod
        b = b / 2
    }
    return ret
}

fun main(args: Array<String>) = bufferOut { readSolveWrite() }

class ev(val idx: Int, val t: Int)

private fun PrintWriter.readSolveWrite() {
    val qqq = readInt()
    repeat(qqq) {
        val n = readInt()
        var aa = readLongs()
        var a = Array<Long>(n, {0})
        for (i in 0..n-1) {
            a[i] = aa[i]
        }
        a.sort()
        var ans = 0.toLong()
        for (i in 0..n-1) {
            ans = max(ans, (n - i) * a[i])
        }
        println(ans)
    }
}