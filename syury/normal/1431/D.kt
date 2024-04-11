import java.util.*

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
        val n = readInt()
        val a = readInts(n)
        var b = IntArray(n)
        var v = IntArray(n)
        var idx = IntArray(n)
        for(i in 0..n-1){
            b[i] = a[i]*n + i
        }
        b = b.sorted().toIntArray()
        for(i in 0..n-1){
            v[i] = b[i]/n
            idx[i] = b[i]%n
        }
        var l = 0
        var r = n - 1
        var seq = IntArray(n)
        var ptr = 0
        var add = 0
        while(l <= r){
            val us = v[l] - add
            if(r - l >= us){
                for(i in 1..us){
                    seq[ptr++] = 1 + idx[r--]
                }
                seq[ptr++] = 1 + idx[l++]
                add = 1
            }
            else{
                for(i in l..r){seq[ptr++] = 1 + idx[i];}
                break
            }
        }
        println(seq.joinToString(" "))
    }
}