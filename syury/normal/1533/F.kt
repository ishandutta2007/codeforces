import java.util.*
import java.math.BigInteger

//private fun readLn() = readLine()!! // string line
//private fun readInt() = readLn().toInt() // single int
//private fun readStrings() = readLn().split(" ") // list of strings
//private fun readInts() = readStrings().map { it.toInt() } // list of ints
//private fun readLongs() = readStrings().map { it.toLong() } // list of longs

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

inline fun <T : Comparable<T> > min(x : T, y : T): T{
    if(x < y){return x;}
    else{return y;}
}

inline fun <T : Comparable<T> > max(x : T, y : T): T{
    if(x > y){return x;}
    else{return y;}
}

fun abs(x: Int): Int{
    if(x < 0){return -x;}
    else{return x;}
}

fun encode(str: String): Long{
    var code = 0L
    for(j in 0..str.length-1){
        val chr = str.get(j) - 'a'
        code = code * 26L + chr.toLong()
    }
    return code
}

fun main(){
    val T = 1//readInt()
    for(t in 1..T){
        val s = readLn()!!
        val n = s.length
        var a = IntArray(n)
        for(i in 0..n-1){
            a[i] = s.get(i) - '0'
        }
        var c0 = IntArray(n)
        var c1 = IntArray(n)
        for(i in 0..n-1){
            if(i > 0){
                c0[i] = c0[i - 1]
                c1[i] = c1[i - 1]
            }
            if(a[i] == 0){c0[i]++}
            else {c1[i]++}
        }
        var ans = IntArray(n)
        for(k in 1..n){
            var cnt = 0
            var i = 0
            while(i < n){
                cnt++
                var l = 1
                var r = n - i + 1
                var p0 = 0
                var p1 = 0
                if(i > 0){
                    p0 = c0[i - 1]
                    p1 = c1[i - 1]
                }
                while(r - l > 1){
                    var mid = (l + r)/2
                    if(i + mid > n || min(c0[i + mid - 1] - p0, c1[i + mid - 1] - p1) > k){
                        r = mid
                    } else {
                        l = mid
                    }
                }
                val len = l
                i += len
            }
            ans[k - 1] = cnt
        }
        println(ans.joinToString(" "))
    }
}