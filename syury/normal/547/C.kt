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

inline fun find_divisors(n: Int): Array<java.util.ArrayList<Int> > {
    var ans = Array<java.util.ArrayList<Int> > (n + 1){java.util.ArrayList<Int>()}
    var divc = Array<Int>(n + 1){0};
    for(i in 1..n){
        for(j in i..n step i)
            ++divc[j]
        ans[i].ensureCapacity(divc[i])
    }
    for(i in 1..n){
        for(j in i..n step i)
            ans[j].add(i)
    }
    return ans
}

fun calcmu(n: Int): IntArray{
    var mu = IntArray(n + 1){1}
    var composite = BooleanArray(n + 1)
    for(i in 2..n){
        if(composite[i]){
            continue
        }
        mu[i] = -1
        for(j in 2*i..n step i){
            composite[j] = true
            mu[j] *= -1
        }
        if(n/i >= i){
            var k = i*i
            for(j in k..n step k){
                mu[j] = 0
            }
        }
    }
    return mu
}

fun main(){
    val T = 1//readInt()
    for(t in 1..T){
        val maxn = 500001
        val (n, q) = readInts(2)
        val a = readInts(n)
        val mu = calcmu(maxn)
        var cnt = IntArray(maxn)
        var has = BooleanArray(maxn)
        val divs = find_divisors(maxn)
        var ans: Long
        ans = 0
        var qa = LongArray(q)
        for(query in 1..q){
            val x = readInt() - 1
            var pairs = 0
            for(d in divs[a[x]]){
                pairs += mu[d] * cnt[d]
            }
            if(has[x]){
                ans -= pairs.toLong()
                if(a[x] == 1)++ans
                for(d in divs[a[x]])
                    --cnt[d]
                has[x] = false
            }
            else{
                ans += pairs.toLong()
                for(d in divs[a[x]])
                    ++cnt[d]
                has[x] = true
            }
            qa[query - 1] = ans
        }
        println(qa.joinToString("\n"))
    }
}