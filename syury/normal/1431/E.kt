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

class scanline(val n: Int, val va: IntArray, val ia: IntArray, val vb: IntArray, val ib: IntArray){
    var seq = IntArray(n)
    fun can(x: Int): Boolean{
        var lb = 0
        var rb = 0
        for(i in 0..n-1){
            val r = va[i] + x
            while(rb < n && vb[rb] <= r){
                ++rb
            }
            if(lb < rb){
                seq[ia[i]] = ib[lb++] + 1
            }
            else
                return false
        }
        return true
    }
    fun getseq(): IntArray{
        return seq
    }
}

fun main(){
    val T = readInt()
    for(t in 1..T){
        val n = readInt()
        val a = readInts(n)
        val b = readInts(n)
        var seq = IntArray(n)
        var cseq = IntArray(n)
        var ans = -1
        for(r in 0..n){
            var curr = 3000000
            var ptr = n - 1
            for(i in r-1 downTo 0){
                cseq[i] = ptr + 1
                curr = min(curr, b[ptr--] - a[i])
            }
            ptr = 0
            for(i in r..n-1){
                cseq[i] = ptr + 1
                curr = min(curr, a[i] - b[ptr++])
            }
            if(ans < curr){
                ans = curr
                for(i in 0..n-1)
                    seq[i] = cseq[i]
            }
        }
        println(seq.joinToString(" "))
    }
}