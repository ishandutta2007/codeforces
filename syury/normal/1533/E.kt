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
        val n = readInt()
        val a = readInts(n).sorted()
        val b = readInts(n + 1).sorted()
        var pref = IntArray(n)
        var suff = IntArray(n)
        for(i in 0..n-1){
            val cu = b[i] - a[i]
            if(i == 0){
                pref[i] = cu
            } else {
                pref[i] = max(pref[i - 1], cu)
            }
        }
        for(i in n-1 downTo 0){
            val cu = b[i + 1] - a[i]
            if(i == n - 1){
                suff[i] = cu
            } else {
                suff[i] = max(suff[i + 1], cu)
            }
        }
        val m = readInt()
        val c = readInts(m)
        var ans = IntArray(m)
        for(i in 0..m-1){
            var l = 0
            var r = n
            if(a[0] >= c[i]){
                l = -1
                r = l
            }
            while(r - l > 1){
                val mid = (l + r)/2
                if(a[mid] >= c[i]){
                    r = mid
                } else {
                    l = mid
                }
            }
            val pos = l + 1
            var curr = -2000000000
            if(pos > 0){curr = max(curr, pref[pos - 1])}
            if(pos < n){curr = max(curr, suff[pos])}
            ans[i] = max(curr, b[pos] - c[i])
        }
        println(ans.joinToString(" "))
    }
}