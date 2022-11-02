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
    val T = readInt()
    for(t in 1..T){
        val (n, m) = readInts(2)
        var a = Array(n) { IntArray(m) }
        var si = -1
        var sj = -1
        var V = 0
        for(i in 0..n-1){
            a[i] = readIntArray(m)
            for(j in 0..m-1){
                if(a[i][j] != 0){
                    si = i
                    sj = j
                    V++
                }
            }
        }
        var vis = 0
        var used = BooleanArray(n*m)
        var seq = ArrayList<Int>()
        fun dfs(v: Int){
            used[v] = true
            vis++
            seq.add(v)
            val i = v/m
            val j = v - i*m
            if(i > 0 && a[i - 1][j] != 0 && !used[(i-1)*m+j]){
                val u = (i-1)*m+j
                dfs(u)
                seq.add(v)
            }
            if(i + 1 < n && a[i + 1][j] != 0 && !used[(i+1)*m+j]){
                val u = (i+1)*m+j
                dfs(u)
                seq.add(v)
            }
            if(j > 0 && a[i][j - 1] != 0 && !used[i*m+j-1]){
                val u = i*m+j-1
                dfs(u)
                seq.add(v)
            }
            if(j + 1 < m && a[i][j + 1] != 0 && !used[i*m+j+1]){
                val u = i*m+j+1
                dfs(u)
                seq.add(v)
            }
        }
        dfs(si*m+sj)
        if(vis != V){
            print(-1)
            print("\n")
            continue
        }
        val len = seq.size
        print(len-V+1)
        print(" ")
        print(V)
        print("\n")
        var cu = IntArray(V)
        for(i in 0..len-V){
            for(j in 0..V-1){
                cu[j] = a[seq[i + j]/m][seq[i + j]%m]
            }
            print(cu.joinToString(" "))
            print("\n")
        }
    }
}