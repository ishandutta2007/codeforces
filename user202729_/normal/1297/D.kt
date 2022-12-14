import java.io.PrintWriter
import java.util.StringTokenizer

fun PrintWriter.solve() {
    val numTest=readInt();
    (1..numTest).forEach{
        val number=readInt()
        var totalBonus=readInt()

        data class Employee( var value: Int, var index: Int, var add: Int)
        val employees=(0 until number).map({ Employee(readInt(), it, 0) })
            .sortedBy({ it.value })

        var last=employees[employees.size-1].value
        employees.reversed().drop(1).forEach {
            --last
            it.add=minOf(totalBonus,last-it.value)
            totalBonus-=it.add
        }

        if(totalBonus!=0){
            val add=(totalBonus+number-1)/number
            employees.reversed().forEach {
                val x=minOf(totalBonus,add)
                it.add+=x
                totalBonus-=x
            }
            assert(totalBonus==0)
        }
        
        var result=IntArray(number)
        employees.forEach{
            result[it.index]=it.add
        }
        println(result.joinToString(" "))
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