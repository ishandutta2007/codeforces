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

class solution(val n: Int, val m: Int, val a: List<Long>, val b: List<Long>, var c: Array<IntArray>, var row: Array<IntArray>, var col: Array<IntArray>){
    var ipos = IntArray(n + m)
    var jpos = IntArray(n + m)
    var sz = 0
    fun solve(): Long{
        sz = 0
        var iptr = 0
        var jptr = 0
        var sum = 0L
        var ans = 0L
        var currc = 0L
        var ci = 0
        var cj = 0
        while(iptr < n && a[iptr] == 0L){
            val cu = c[iptr][0].toLong()
            if(cu > currc){
                currc = cu
                ci = iptr
                cj = 0
            }
            ++iptr
        }
        while(jptr < m && b[jptr] == 0L){
            val pos = col[jptr][iptr - 1]
            val cu = c[pos][jptr].toLong()
            if(cu > currc){
                currc = cu
                ci = pos
                cj = jptr
            }
            ++jptr
        }
        //println("start")
        while(iptr < n || jptr < m){
            var tillNext = 10000000000000L
            //println(iptr)
            //println(jptr)
            if(iptr < n)
                tillNext = min(tillNext, a[iptr] - sum)
            if(jptr < m)
                tillNext = min(tillNext, b[jptr] - sum)
            var steps = tillNext/currc
            if(steps * currc < tillNext)
                ++steps
            ans += steps
            sum += currc * steps
            ipos[sz] = ci
            jpos[sz] = cj
            ++sz
            while(iptr < n && a[iptr] <= sum){
                val pos = row[iptr][jptr - 1]
                val cu = c[iptr][pos].toLong()
                if(cu > currc){
                    currc = cu
                    ci = iptr
                    cj = pos
                }
                ++iptr
            }
            while(jptr < m && b[jptr] <= sum){
                val pos = col[jptr][iptr - 1]
                val cu = c[pos][jptr].toLong()
                if(cu > currc){
                    currc = cu
                    ci = pos
                    cj = jptr
                }
                ++jptr
            }
        }
        return ans
    }
    fun change(i: Int, j: Int, d: Int){
        c[i][j] += d
    }
    fun gets(): Int{return sz;}
    fun geti(): IntArray{return ipos.copyOf();}
    fun getj(): IntArray{return jpos.copyOf();}
}

fun main(){
    val T = 1//readInt()
    for(t in 1..T){
        val (n, m, k) = readInts(3)
        val a = readLongs(n)
        val b = readLongs(m)
        var c = Array(n){IntArray(m){0}}
        var rowmax = Array(n){IntArray(m){0}}
        var colmax = Array(m){IntArray(n){0}}
        for(i in 0..n-1){
            val curr = readInts(m)
            for(j in 0..m-1){
                c[i][j] = curr[j]
                rowmax[i][j] = j
                if(j > 0 && curr[rowmax[i][j - 1]] >= curr[j])
                    rowmax[i][j] = rowmax[i][j - 1]
            }
            //println(rowmax[i].joinToString())
        }
        for(j in 0..m-1){
            for(i in 0..n-1){
                colmax[j][i] = i
                if(i > 0 && c[colmax[j][i - 1]][j] >= c[i][j])
                    colmax[j][i] = colmax[j][i - 1]
            }
            //println(colmax[j].joinToString())
        }
        var solver = solution(n, m, a, b, c, rowmax, colmax)
        var ans = solver.solve()
        val sz = solver.gets()
        val ipos = solver.geti()
        val jpos = solver.getj()
        for(id in 0..sz-1){
            val i = ipos[id]
            val j = jpos[id]
            solver.change(i, j, k)
            ans = min(ans, solver.solve())
            solver.change(i, j, -k)
        }
        println(ans)
    }
}