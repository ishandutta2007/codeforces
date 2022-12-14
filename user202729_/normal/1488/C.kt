import java.io.PrintWriter
import java.io.File
import java.util.StringTokenizer

fun PrintWriter.solve() {
    (1..readInt()).forEach{_->
        val n=readInt()
        val x=readInt()
        val y=readInt()
        val l=minOf(x, y)
        val r=maxOf(x, y)

        var result=n*3 // not exceed 10^6

        val excessCover={next: Int, d: Int->
            if(next<d) {-2*n} // impossible.
            //if(next==d) return 0
            //if(next==d+1) return 0
            //if(next==d+2) return 1
            else if(next<d*3) { (next-d)/2 }
            else next-d*2
        }

        for(i in 23 downTo 0){ // I keep writing downTo 1 somehow
            val next=result-(1 shl i)
            if(excessCover(next, l-1)+excessCover(next, n-r)>=r-l-1)
                result=next
        }
        printf("%d\n", result)
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