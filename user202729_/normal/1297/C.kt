import java.io.PrintWriter
import java.util.StringTokenizer
import kotlin.math.abs

fun PrintWriter.solve() {
    val numTest=readInt();
    (1..numTest).forEach{
        val number=readInt();
        val (negative, positive)=(0 until number).map({ Pair(readInt(), it) })
            .filter({it.first!=0}).partition({it.first<0});
        var item=positive.minBy({it.first})!!;
        if(!negative.isEmpty()){
            val other=negative.maxBy({it.first})!!;
            if(-other.first<item.first){
                item=other
            }
        }
        
        positive.sumBy({it.first})

        var result=CharArray(number, {'0'})
        positive.forEach{result[it.second]='1'}
        result[item.second]= if(result[item.second]=='0') '1' else '0'
        println(
                positive.sumBy({it.first})-abs(item.first)
        )
        println(result)
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