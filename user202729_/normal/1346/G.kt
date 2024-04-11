// :(
import java.io.PrintWriter
import java.io.File
import java.util.StringTokenizer

fun PrintWriter.solve() {
    val numPeriod=readInt()
    val numTime=readInt()
    val periods=IntArray(numPeriod){readInt()}
    val times=IntArray(numTime){readInt()}

    if(numTime==2){
        printf("YES\n%d %d\n%d %d\n", times[0], periods[0], times[1], periods[0])
        return
    }

    val maxPeriod=maxOf(periods.max()!!, times.last()-times[0])
    val factors=List(maxPeriod+1){mutableListOf<Int>()}
    //periods.sort()
    periods.forEach{
        if(factors[it].isEmpty()){
            for(multiple in it..maxPeriod step it)
                factors[multiple].add(it)
        }
    }

    listOf(
            Pair(times[0], times[1]),
            Pair(times[0], times[2]),
            Pair(times[1], times[2]))
    .forEach{(first, sec)->
        val step=sec-first
        factors[step].forEach{period->
            val remaining=times.filter{(it-first)%period!=0}
            if(remaining.size==0){
                printf("YES\n%d %d\n%d %d\n", first, period, times[0], periods[0])
                return@solve
            }
            if(remaining.size==1){
                printf("YES\n%d %d\n%d %d\n", first, period, remaining[0], periods[0])
                return@solve
            }

            var requiredOtherStep=remaining[1]-remaining[0]
            for(index in 2..remaining.lastIndex){
                var x=remaining[index]-remaining[index-1]
                while(x!=0){
                    val tmp=requiredOtherStep%x
                    requiredOtherStep=x
                    x=tmp
                }
            }
            if(!factors[requiredOtherStep].isEmpty()){
                printf("YES\n%d %d\n%d %d\n", first, period, remaining[0], factors[requiredOtherStep][0])
                return@solve
            }
        }
    }
    println("NO")
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