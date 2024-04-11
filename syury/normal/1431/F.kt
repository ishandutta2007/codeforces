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
    val T = 1//readInt()
    for(t in 1..T){
        val (n, k, x) = readInts(3)
        val b = readInts(n)
        if(k >= n){
            println(0)
            return
        }
        var l = 0L
        var r = 10000000000L
        var q = java.util.PriorityQueue<Int>()
        while(r - l > 1){
            val mid = (l + r)/2
            var can = false
            var i = 0
            var del = 0
            while(i < n){
                q.clear()
                var j = i
                var cnt = 0
                var sum = 0L
                while(j < n && cnt < x){
                    val curr = b[j].toLong()
                    q.add(-b[j])
                    sum += curr
                    ++cnt
                    while(sum > mid){
                        val dl = q.poll()
                        sum += dl.toLong()
                        ++del
                        --cnt
                    }
                    ++j
                }
                i = j
            }
            can = (del <= k)
            if(can)
                r = mid
            else
                l = mid
        }
        println(r)
    }
}