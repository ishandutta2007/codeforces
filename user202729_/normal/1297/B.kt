import java.io.PrintWriter
import java.util.StringTokenizer

fun PrintWriter.solve() {
    val numTest=readInt();
    (1..numTest).forEach{
        val number=readInt();
        var events=ArrayList<Pair<Int,Int /* delta */>>();
        (1..number).forEach{
            events.add(Pair(readInt(), 1))
            events.add(Pair(readInt()+1, -1))
        }
        events.sortBy { it.first }
        var degree=0


        run{
            for((index, value) in events.withIndex()){
                degree+=value.second
                if(index==events.size-1 || value.first!=events[index+1].first){
                    if(degree==1){
                        println(value.first)
                        return@run
                    }
                }
            }

            println(-1)
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