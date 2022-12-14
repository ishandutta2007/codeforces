import java.io.PrintWriter
import java.io.File
import java.util.StringTokenizer

fun PrintWriter.solve() {
    for(x in 1..readInt()){
        val numNode=readInt()
        val numEdge=readInt()

        val edges=(1..numEdge).map{ Triple(readInt()-1, readInt()-1, readInt()) }
        val value=IntArray(numNode){0}
        edges.forEach{(u, v, w)->
            value[u]=maxOf(value[u], w)
            value[v]=maxOf(value[v], w)
        }
        if(edges.all{(u, v, w)-> minOf(value[u], value[v])==w}){
            println("YES")
            value.forEach{printf("%d ", it)}
            println()
        }else{
            println("NO")
        }
    }
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