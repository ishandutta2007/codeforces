// Even after the contest, it's not allowed to solve the problems
// in languages other than Kotlin...

// :(

import java.io.PrintWriter
import java.util.StringTokenizer

fun PrintWriter.solve() {
    val numTest=readInt()
    (1..numTest).forEach{
        val string=readLn()
        val f=Array(string.length+1) { Array(it+1) { Pair("~", "") } }
        // f[index][len] = minimum string R with length (len) such that the prefix with length (index)
        // can be divided into two strings R and a prefix of R (with length R-len), and the partition

        assert("~">"z")
        f[0][0]=Pair("", "")
        var result=Pair("~", "")

        val comp=compareBy<Pair<String, String>>{it.first}

        for(index in 0 until string.length){
            f[index].mapIndexed {len, (s, trace) ->
                if(s=="~") return@mapIndexed
                assert(index-len<=len)
                if(index-len<len){
                    if(string[index]==s[index-len]){
                        f[index+1][len]=minOf(f[index+1][len], Pair(s, trace+"B"), comp)
                        // can't use `let` or `run` here to avoid repeating the assignment target?...
                    }else{
                        if(string[index]<s[index-len])
                            result=minOf(result, Pair(
                                    s,
                                    trace+"B" + "B".repeat(string.length-1-trace.length)
                            ), comp)
                        else
                            result=minOf(result, Pair(
                                    s.substring(0 until index-len)+string[index],
                                    trace+"B" + "R".repeat(string.length-1-trace.length)
                            ), comp)

                        // note that it's not efficient to copy the string every time.
                        // using a trie or something like that should be faster.
                    }
                }

                f[index+1][len+1]=minOf(f[index+1][len+1], Pair(s+string[index], trace+"R"), comp)
            }
        }

        /*
        for(index in 0 until string.length){
            f[index].mapIndexed {len, (s, trace) ->
                printf("%s %s %s %s\n", index, len, s, trace)
            }
        }
        */

        assert(f[string.length].size==string.length+1)
        result=minOf(result, f[string.length].minWith(comp) !!, comp)
        assert(result.second.length==string.length)
        println(result.second)
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