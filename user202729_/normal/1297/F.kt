import java.io.PrintWriter
import java.util.StringTokenizer

fun PrintWriter.solve() {
    val numTest=readInt();
    (1..numTest).forEach{
        val number=readInt()
        var limit=readInt()

        data class item( var last: Int, var index: Int )
        var pend=sortedSetOf<item>(compareBy({it.last}, {it.index}))

        val movies=(0 until number).map{
            Triple(readInt(), readInt(), it)
        }.sortedBy({it.first})
        var process=0

        var result=IntArray(number,{0})
        var resultValue=0

        var value=-1
        while(process<movies.size || !pend.isEmpty()){
            value+=1
            if(pend.isEmpty()) value=movies[process].first
            assert(process==movies.size || movies[process].first>=value)

            while(process<movies.size && movies[process].first==value){
                pend.add(item(
                        movies[process].second, movies[process].third
                ))
                ++process
            }

            run{
                repeat(limit){
                    val cur=pend.pollFirst()
                    if(cur==null) return@run
                    result[cur.index]=value
                    resultValue=maxOf(resultValue, maxOf(0,value-cur.last))
                }
            }
        }

        println(resultValue)
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