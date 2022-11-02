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
        var a = Array(n) { IntArray(m) }
        for(i in 0..n-1){
            val s = readLn()!!
            for(j in 0..m-1){
                a[i][j] = (s.get(j) - 'A').toInt()
            }
        }
        var ans = LongArray(5)
        var dp = LongArray(32)
        var b = Array(n) { IntArray(m) }
        var up = Array(n) { IntArray(m) }
        var stk = IntArray(m)
        var sz = 0
        for(mask in 1..31){
            var cnt = 0L
            for(i in 0..n-1){
                for(j in 0..m-1){
                    if((mask and (1 shl a[i][j])) > 0){
                        b[i][j] = 1
                    } else {
                        b[i][j] = 0
                    }
                    if(b[i][j] == 1){
                        up[i][j] = 1
                        if(i > 0){up[i][j] += up[i - 1][j]}
                    } else {
                        up[i][j] = 0
                    }
                }
            }
            for(i in 0..n-1){
                sz = 0
                var bal = 0
                for(j in 0..m-1){
                    val ones = up[i][j]
                    while(sz > 0 && up[i][stk[sz - 1]] > ones){
                        if(sz > 1){
                            bal -= (stk[sz - 1] - stk[sz - 2]) * up[i][stk[sz - 1]]
                        } else {
                            bal -= (1 + stk[sz - 1]) * up[i][stk[sz - 1]]
                        }
                        sz--
                    }
                    if(sz > 0){
                        bal += (j - stk[sz - 1]) * ones
                    } else {
                        bal += ones * (1 + j)
                    }
                    stk[sz++] = j
                    cnt += (bal).toLong()
                    //if(mask == 2){println(bal)}
                }
            }
            //println(mask)
            //println(cnt)
            dp[mask] = cnt
            //ans[cols-1] += cnt
        }
        for(mask in 1..31){
            var sub = mask
            while(sub > 0){
                if(sub != mask){dp[mask] -= dp[sub]}
                sub = (sub - 1) and mask
            }
            var cols = 0
            for(i in 0..4){
                if((mask and (1 shl i)) > 0){cols++}
            }
            ans[cols - 1] += dp[mask]
        }
        println(ans.joinToString(" "))
    }
}