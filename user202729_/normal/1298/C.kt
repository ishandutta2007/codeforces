import java.io.PrintWriter
import java.util.StringTokenizer

fun PrintWriter.solve() {
    val len=readInt();
    //var last='a', lastCount=0, result=0; // integer types default to long?...
    //var (last, lastCount, result)=listOf('a', 0, 0);
    var last='a'
    var lastCount=0
    var result=0

    var word:String=read()
    for (ch in word.asIterable()){
        if(ch==last){
            ++lastCount
            if(lastCount>=3 && ch=='x') ++result
        }else{
            lastCount=1
            last=ch
        }
    }
    println(result)
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