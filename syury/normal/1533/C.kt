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

fun main(){
    val T = readInt()
    for(t in 1..T){
        val (n, k)  = readInts(2)
        val s = readLn()!!
        var like = BooleanArray(n)
        var alive = IntArray(n)
        var cnt = n
        var liked = 0
        for(i in 0..n-1){
            alive[i] = i
            if(s.get(i) == '1'){
                like[i] = true
                liked++
            } else {
                like[i] = false
            }
        }
        if(liked == 0){
            print("0\n")
            continue
        }
        var pos = 0
        while(liked > 0){
            if(cnt < n){
                pos = (pos + k - 1)%cnt
            }
            var who = alive[pos]
            if(like[who]){
                liked--
            }
            var ptr = 0
            for(i in 0..cnt-1){
                if(alive[i] != who){
                    alive[ptr++] = alive[i]
                }
            }
            if(pos == cnt - 1){pos = 0}
            cnt--
        }
        print(n - cnt)
        print("\n")
    }
}