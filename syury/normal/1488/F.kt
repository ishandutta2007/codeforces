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
    var t = LongArray(n*4+3){0}
    var tag = LongArray(n*4+3){0}
    private fun push(v: Int, L: Int, R: Int){
        if(tag[v] == 0L){
            return
        }
        t[2*v] = L.toLong() * tag[v]
        t[2*v+1] = R.toLong() * tag[v]
        tag[2*v] = tag[v]
        tag[2*v+1] = tag[v]
        tag[v] = 0L
    }
    private fun upd(v: Int, l: Int, r: Int, ul: Int, ur: Int, value: Long){
        if(ul > ur){
            return
        }
        if(l == ul && r == ur){
            t[v] = value * (r - l + 1).toLong()
            tag[v] = value
            return
        }
        val mid = (l + r)/2;
        push(v, mid - l + 1, r - mid)
        upd(2*v, l, mid, ul, min(ur, mid), value)
        upd(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, value)
        t[v] = t[2*v] + t[2*v+1]
    }
    fun update(l: Int, r: Int, value: Long){
        upd(1, 0, n - 1, l, r, value)
    }
    private fun que(v: Int, l: Int, r: Int, ul: Int, ur: Int): Long{
        if(ul > ur){
            return 0L
        }
        if(l == ul && r == ur){
            return t[v]
        }
        val mid = (l + r)/2;
        push(v, mid - l + 1, r - mid)
        return que(2*v, l, mid, ul, min(ur, mid)) + que(2*v + 1, mid + 1, r, max(ul, mid + 1), ur)
    }
    fun query(l: Int, r: Int): Long{
        return que(1, 0, n - 1, l, r)
    }
}

class Item(public val x: Int, public val l: Int, public val r: Int)

fun main(){
    val T = 1//readInt()
    for(t in 1..T){
        val n = readInt()
        val c = readInts(n)
        val q = readInt()
        var ans = LongArray(q)
        var its = ArrayList<Item>()
        for(i in 0..q-1){
            val (l, r) = readInts(2)
            its.add(Item(i, l - 1, r - 1))
        }
        val qs = its.sortedBy{it.r}
        var ptr = 0
        var t = SegTree(n)
        var stk = IntArray(n)
        var stksz = 0
        for(i in 0..n-1){
            while(stksz > 0 && c[stk[stksz - 1]] < c[i]){
                --stksz;
            }
            var l = 0
            if(stksz > 0){
                l = stk[stksz - 1] + 1
            }
            t.update(l, i, c[i].toLong())
            stk[stksz++] = i
            while(ptr < qs.size && qs[ptr].r == i){
                ans[qs[ptr].x] = t.query(qs[ptr].l, qs[ptr].r)
                ++ptr
            }
        }
        println(ans.joinToString(" "))
    }
}