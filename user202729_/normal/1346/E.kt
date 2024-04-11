import java.io.PrintWriter
import java.io.File
import java.util.StringTokenizer

fun PrintWriter.solve() {
    val numBall=readInt()
    val numSwap=readInt()
    val pos=readInt()-1

    val dat=IntArray(numBall){numSwap+1}
    dat[pos]=0
    for(it in 1..numSwap){
        val x=readInt()-1
        val y=readInt()-1
        val datx=minOf(dat[y], dat[x]+1)
        val daty=minOf(dat[x], dat[y]+1)
        dat[x]=datx
        dat[y]=daty
    }
    
    dat.forEach{printf("%d ", if(it==numSwap+1) -1 else it)}
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