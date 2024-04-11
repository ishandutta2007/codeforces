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
        var (n, x, y) = readInts(3)
        if(x > y){
            x = y.also{y = x}
        }
        if(x + 1 == y){
            println(max(x - 1, n - y))
        }
        else{
            var ans = n + 1488
            for(i in x..y-1){
                val L = min(x - 1 + i - 1, i - x + i - 1)
                val R = min(y - i - 1 + n - (i + 1), n - y + n - (i + 1))
                ans = min(ans, max(L, R))
            }
            println(ans)
        }
    }
}