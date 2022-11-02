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

class Encoder(val pwr: IntArray){
    fun encode(len: Int, p2: Int, p3: Int, p5: Int, p7: Int): Int{
        if(p2 < 0 || p3 < 0 || p5 < 0 || p7 < 0)
            return -1
        return len * pwr[0] * pwr[1] * pwr[2] * pwr[3] + p2 * pwr[1] * pwr[2] * pwr[3] + p3 * pwr[2] * pwr[3] + p5 * pwr[3] + p7
    }
}

inline fun add(dp: HashMap<Int, Long>, state: Int, value: Long){
    if(!dp.containsKey(state))
        dp.put(state, value)
    else
        dp[state] = dp[state]!! + value
}

inline fun add(dp: HashMap<Int, Long>, state: Int, value: Int){
    add(dp, state, value.toLong())
}

inline fun getdp(dp: HashMap<Int, Long>, state: Int): Long{
    if(!dp.containsKey(state))
        return 0L
    else
        return dp[state]!!
}

fun main(){
    val T = 1//readInt()
    for(t in 1..T){
        var (m, kk) = readInts(2)
        var k = kk.toLong()
        var pwr = IntArray(4){0}
        while(m%2 == 0){
            ++pwr[0]
            m /= 2
        }
        while(m%3 == 0){
            ++pwr[1]
            m /= 3
        }
        while(m%5 == 0){
            ++pwr[2]
            m /= 5
        }
        while(m%7 == 0){
            ++pwr[3]
            m /= 7
        }
        if(m > 1){
            println("-1")
            return
        }
        var kek = IntArray(4)
        for(i in 0..3)
            kek[i] = 1 + pwr[i]
        val enc = Encoder(kek)
        var dp = HashMap<Int, Long>()
        var who = 0
        dp.put(enc.encode(0, 0, 0, 0, 0), 1L)
        for(len in 1..50000){
            for(p2 in 0..pwr[0]){
                for(p3 in 0..pwr[1]){
                    for(p5 in 0..pwr[2]){
                        for(p7 in 0..pwr[3]){
                            val old = enc.encode(len - 1, p2, p3, p5, p7)
                            if(!dp.containsKey(old))
                                continue
                            val oldval: Long
                            oldval = dp[old]!!
                            add(dp, enc.encode(len, p2, p3, p5, p7), oldval)
                            if(p2 + 1 <= pwr[0])
                                add(dp, enc.encode(len, p2 + 1, p3, p5, p7), oldval)
                            if(p3 + 1 <= pwr[1])
                                add(dp, enc.encode(len, p2, p3 + 1, p5, p7), oldval)
                            if(p2 + 2 <= pwr[0])
                                add(dp, enc.encode(len, p2 + 2, p3, p5, p7), oldval)
                            if(p5 + 1 <= pwr[2])
                                add(dp, enc.encode(len, p2, p3, p5 + 1, p7), oldval)
                            if(p2 + 1 <= pwr[0] && p3 + 1 <= pwr[1])
                                add(dp, enc.encode(len, p2 + 1, p3 + 1, p5, p7), oldval)
                            if(p7 + 1 <= pwr[3])
                                add(dp, enc.encode(len, p2, p3, p5, p7 + 1), oldval)
                            if(p2 + 3 <= pwr[0])
                                add(dp, enc.encode(len, p2 + 3, p3, p5, p7), oldval)
                            if(p3 + 2 <= pwr[1])
                                add(dp, enc.encode(len, p2, p3 + 2, p5, p7), oldval)
                        }
                    }
                }
            }
            val fin = enc.encode(len, pwr[0], pwr[1], pwr[2], pwr[3])
            if(dp.containsKey(fin) && dp[fin]!! >= k){
                who = len
                break
            }
            k -= getdp(dp, fin)
        }
        var ans = CharArray(who)
        var p2 = pwr[0]
        var p3 = pwr[1]
        var p5 = pwr[2]
        var p7 = pwr[3]
        for(len in who downTo 1){
            var carry: Long
            carry = 0
            var old: Long
            old = carry
            carry += getdp(dp, enc.encode(len - 1, p2, p3, p5, p7))
            if(carry >= k){
                k -= old
                ans[who - len] = '1'
                continue
            }
            old = carry
            carry += getdp(dp, enc.encode(len - 1, p2 - 1, p3, p5, p7))
            if(carry >= k){
                k -= old
                --p2
                ans[who - len] = '2'
                continue
            }
            old = carry
            carry += getdp(dp, enc.encode(len - 1, p2, p3 - 1, p5, p7))
            if(carry >= k){
                k -= old
                --p3
                ans[who - len] = '3'
                continue
            }
            old = carry
            carry += getdp(dp, enc.encode(len - 1, p2 - 2, p3, p5, p7))
            if(carry >= k){
                k -= old
                p2 -= 2
                ans[who - len] = '4'
                continue
            }
            old = carry
            carry += getdp(dp, enc.encode(len - 1, p2, p3, p5 - 1, p7))
            if(carry >= k){
                k -= old
                --p5
                ans[who - len] = '5'
                continue
            }
            old = carry
            carry += getdp(dp, enc.encode(len - 1, p2 - 1, p3 - 1, p5, p7))
            if(carry >= k){
                k -= old
                --p2
                --p3
                ans[who - len] = '6'
                continue
            }
            old = carry
            carry += getdp(dp, enc.encode(len - 1, p2, p3, p5, p7 - 1))
            if(carry >= k){
                k -= old
                --p7
                ans[who - len] = '7'
                continue
            }
            old = carry
            carry += getdp(dp, enc.encode(len - 1, p2 - 3, p3, p5, p7))
            if(carry >= k){
                k -= old
                p2 -= 3
                ans[who - len] = '8'
                continue
            }
            old = carry
            carry += getdp(dp, enc.encode(len - 1, p2, p3 - 2, p5, p7))
            if(carry >= k){
                k -= old
                p3 -= 2
                ans[who - len] = '9'
                continue
            }
        }
        println(ans.joinToString(""))
    }
}