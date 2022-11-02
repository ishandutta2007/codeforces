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

class Edge(public val v: Int, public val u: Int, public val w: Long){}

fun main(){
    val T = 1//readInt()
    for(t in 1..T){
        val (n, m) = readInts(2)
        var e = ArrayList<Edge>()
        val a = readLongs(n)
        for (i in 0..m-1){
            val (v, u) = readInts(2)
            val w = readLong()
            e.add(Edge(v - 1, u - 1, w))
        }
        var pos = 0
        for (i in 1..n-1){
            if (a[pos] > a[i]){
                pos = i
            }
        }
        for (i in 0..n-1){
            if (i != pos){
                e.add(Edge(i, pos, a[i] + a[pos]))
            }
        }
        val edges = e.sortedBy{it.w}
        var p = IntArray(n)
        var sz = IntArray(n){1}
        for (i in 0..n-1){
            p[i] = i
        }
        var ans = 0L
        for (edge in edges){
            var v = edge.v
            var u = edge.u
            val w = edge.w
            while (v != p[v]){
                v = p[v]
            }
            while (u != p[u]){
                u = p[u]
            }
            if (v != u){
                ans += w
                if (sz[v] > sz[u]) {
                    p[u] = v
                    sz[v] += sz[u]
                }
                else{
                    p[v] = u
                    sz[u] += sz[v]
                }
            }
        }
        println(ans)
    }
}