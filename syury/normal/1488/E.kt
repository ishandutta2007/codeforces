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

const val inf = 148869228

class SegTree(val n: Int){
    var t = IntArray(n*4+3)
    fun build(){
        for(i in 0..t.size-1){
            t[i] = 1
        }
    }
    private fun upd(v: Int, l: Int, r: Int, pos: Int, value: Int){
        if(l == r){
            t[v] = max(t[v], value)
            return
        }
        val mid = (l + r)/2
        if(pos <= mid){
            upd(2*v, l, mid, pos, value)
        }
        else{
            upd(2*v + 1, mid + 1, r, pos, value)
        }
        t[v] = max(t[2*v], t[2*v+1])
    }
    fun update(pos: Int, value: Int){
        upd(1, 0, n - 1, pos, value)
    }
    private fun que(v: Int, l: Int, r: Int, ul: Int, ur: Int): Int{
        if(ul > ur){
            return -inf
        }
        if(l == ul && r == ur){
            return t[v]
        }
        val mid = (l + r)/2;
        return max(que(2*v, l, mid, ul, min(ur, mid)), que(2*v + 1, mid + 1, r, max(ul, mid + 1), ur))
    }
    fun query(l: Int, r: Int): Int{
        return que(1, 0, n - 1, l, r)
    }
}

class Item(public val x: Int, public val len: Int, public val l: Int, public val r: Int)

fun main(){
    val T = readInt()
    for(t in 1..T){
        val n = readInt()
        val inp = readInts(n)
        var a = IntArray(n)
        var dp = IntArray(n + 1){1}
        var was = IntArray(n + 1){-1}
        for(i in 0..n-1){
            a[i] = inp[i]
        }
        var ans = 1
        var t = SegTree(n)
        t.build()
        var its = ArrayList<Item>()
        for(i in 0..n-1){
            if(-1 != was[a[i]]){
                val j = was[a[i]]
                its.add(Item(a[i], i - j, j, i))
            }
            else{
                was[a[i]] = i
            }
        }
        var evts = its.sortedBy{it.r}
        for(e in evts){
            val x = e.x
            dp[x] = max(dp[x], 2)
            val l = e.l
            val r = e.r
            dp[x] = max(dp[x], t.query(l + 1, r - 1) + 2)
            t.update(l, dp[x])
            ans = max(ans, dp[x])
        }
        println(ans)
    }
}