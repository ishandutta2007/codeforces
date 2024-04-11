










import java.io.PrintWriter
import java.io.File
import java.util.StringTokenizer

fun PrintWriter.solve() {
    val numQuery=readInt()
    val numStop=readInt()
    val queries=List(numQuery){Pair(-readInt(), readInt())}

    val stops={
        val stops_=List(2){mutableMapOf<Int, MutableList<Int>>()} // x-y-> stop x values
        for(z in 1..numStop){
            val x=-readInt()
            val y=readInt()
            stops_[(x-y) and 1].getOrPut(x-y, {mutableListOf<Int>()}).add(x)
        }
        stops_.map{it.map{(key, value)->
            value.sort()
            Pair(key, value.distinct().toIntArray()) // <- slightly inefficient
        }.toMap<Int, IntArray>()}
    }()

    queries.forEach{(x, y)->
        val tmp=stops[(x-y) and 1]
        val (a, b, c)=listOf(Pair(x, y), Pair(x-2, y), Pair(x, y-2)).map{(x, y)->
            val tmp2=tmp[x-y]
            if(tmp2==null){
                null
            }else{
                val index=tmp2.binarySearch(x)
                if(index<0) {
                    if(index==-1) null
                    else x-tmp2[-index-2]
                } else 0
            }
        }
        var result=Int.MAX_VALUE
        if(a!=null){
            result=minOf(result, a)
        }
        if(b!=null && c!=null){
            result=minOf(result, maxOf(b, c)+1)
        }
        printf("%d ", if(result==Int.MAX_VALUE) -1 else result)
    }
    println()
}

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

@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

fun main() { _writer.solve(); _writer.flush() }