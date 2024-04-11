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


fun main(){
    val T = readInt()
    for(t in 1..T){
        val (n, s) = readLongs(2)
        var L = 1L
        var R = s + 1
        while (R - L > 1) {
            val mid = (L + R)/2
            var can = true
            var idx = n
            var x = mid
            var kek = 0L
            while(idx > 0 && x > 1){
                kek += x
                if(kek > s){break;}
                if(x%2 == 1L){x = x/2 + 1;}
                else{x = x/2;}
                --idx
            }
            if(kek <= s && idx > 0)
                kek += idx
            can = kek <= s
            if(can){
                L = mid
            }
            else{
                R = mid
            }
        }
        println(L)
    }
}