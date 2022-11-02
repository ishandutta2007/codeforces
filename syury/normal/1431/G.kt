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
    val T = 1//readInt()
    for(t in 1..T){
        val (n, k) = readInts(2)
        val a = readInts(n).sorted()
        var f = Array(n + 1) {IntArray(n + 1){0}}
        var dp = Array(n + 1) {IntArray(n + 1){0}}
        for(i in n-2 downTo 0){
            f[i][2] = a[i + 1] - a[i]
            for(len in 4..n step 2){
                if(i + len > n){
                    break
                }
                f[i][len] = f[i + 1][len - 2] + a[i + len - 1] - a[i]
            }
        }
        for(i in n-2 downTo 0){
            for(mv in 1..k+1){
                var cu = dp[i + 1][mv]
                for(cmov in 1..mv){
                    var j = i + cmov*2
                    if(j > n){break}
                    var cv = dp[j][mv - cmov] + f[i][cmov*2]
                    cu = max(cu, cv)
                }
                dp[i][mv] = cu
                //println(cu)
            }
        }
        println(dp[0][k])
    }
}