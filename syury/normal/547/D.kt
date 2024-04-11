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
        val X = 200001
        val n = readInt()
        var x = IntArray(n+X*2)
        var y = IntArray(n+X*2)
        var un = IntArray(X*2+228){0}
        var gr = Array<ArrayList<Int> >(X*2+228){ArrayList<Int>()}
        for(i in 0..n-1){
            val (cx, cy) = readInts(2)
            x[i] = cx
            y[i] = cy + X
            gr[cx].add(i)
            gr[cy + X].add(i)
        }
        var ptr = 0
        for(i in 0..2*X-1){
            if((gr[i].size and 1) == 1){
                gr[i].add(n + ptr)
                gr[2*X].add(n + ptr)
                x[n + ptr] = i
                y[n + ptr] = 2*X
                ++ptr
            }
        }
        var used = BooleanArray(5*X)
        var stk = IntArray(5*X)
        var who = IntArray(5*X)
        var sz = 0
        var color = CharArray(n)
        var seq = ArrayList<Int>()
        var ones = ArrayList<Int>()
        var zeros = ArrayList<Int>()
        for(i in 2*X downTo 0){
            if(un[i] == gr[i].size)
                continue
            sz = 0
            who[0] = -1
            stk[sz++] = i
            while(sz > 0){
                val v = stk[sz - 1]
                if(un[v] < gr[v].size){
                    val e = gr[v][un[v]]
                    ++un[v]
                    if(used[e])
                        continue
                    var u = x[e]
                    if(u == v)u = y[e]
                    used[e] = true
                    who[sz] = e
                    stk[sz++] = u
                }
                else{
                    if(who[sz - 1] != -1)
                        seq.add(who[sz - 1])
                    --sz
                }
            }
        }
        //println(seq.joinToString(" "))
        for(i in 0..seq.size-1){
            val e = seq[i]
            if(e < n){
                if((i and 1)==1){
                    color[e] = 'b'
                }
                else{
                    color[e] = 'r'
                }
            }
        }
        println(color.joinToString(""))
    }
}