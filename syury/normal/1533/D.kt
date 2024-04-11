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
        val (n, m) = readInts(2)
        var idx = HashMap<Long, Int>()
        var la = IntArray(n)
        for(i in 0..n-1){
            la[i] = -1
            val str = readLn()!!
            idx.put(encode(str), i)
        }
        val q = readInt()
        var L = LongArray(m + 2)
        var R = LongArray(m + 2)
        for(i in 0..q-1){
            var ans = 0
            val str = readLn()!!
            L[0] = 0
            for(j in 0..m){
                L[j+1] = L[j] * 26L + (str.get(j) - 'a').toLong()
            }
            R[m+1] = 0
            var pwr = 1L
            for(j in m downTo 0){
                R[j] = R[j + 1] + (str.get(j) - 'a').toLong() * pwr
                val code = R[j+1] + L[j] * pwr
                pwr *= 26L
                if (idx.containsKey(code)) {
                    val who = idx[code]!!
                    if(la[who] < i){
                        la[who] = i
                        ans++
                    }
                }
            }
            print(ans)
            print("\n")
        }
    }
}