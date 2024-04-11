import java.io.PrintWriter
import java.io.File
import java.util.StringTokenizer

fun PrintWriter.solve() {
    val numRow=readInt()
    val numCol=readInt()
    val numUpdate=readInt()
    val table=List(numRow){ IntArray(numCol){readInt()} }

    val sumRow: LongArray=table.map{it.fold(0L) {a, b->a+b}}.toLongArray()
    val sumCol: LongArray=table.fold(LongArray(numCol){0}) {a: LongArray, b->
        a.indices.forEach{
            a[it]=a[it]+b[it]
        }
        a
    }

    val compute1={it: LongArray->
        var cur=it.withIndex().map{(index, value)->value*index}.sum()
        val sum=it.sum()
        var sumAfter=sum
        var result=cur

        it.forEach{
            sumAfter-=it
            cur-=sumAfter
            cur+=(sum-sumAfter)
            result=minOf(result, cur)
        }
        result
    }

    val compute={
        compute1(sumRow)+compute1(sumCol)
    }

    print(compute())
    for(x in 1..numUpdate){
        val row=readInt()-1
        val col=readInt()-1
        val delta=readInt()-table[row][col]
        table[row][col]+=delta
        sumRow[row]+=delta.toLong()
        sumCol[col]+=delta.toLong()

        printf(" %d", compute())
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