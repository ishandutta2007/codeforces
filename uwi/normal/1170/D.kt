//package d

import java.io.PrintWriter
import java.util.*

fun solve() {
    val n = ni()
    val a = na()
    var m = 0
    for(v in a){
        if(v == -1){
            m++
        }
    }
    val ls: MutableList<MutableList<Int>> = mutableListOf()
    for(i in 1..m){
        ls.add(mutableListOf())
    }
    val ts = sortedSetOf<Int>()
    for(i in 1..m){
        ts.add(i-1)
    }
    var cur = -1
    for(v in a){
        var nex = ts.higher(cur)
        if(nex == null){
            nex = ts.higher(-1)
        }
        var nnex = nex!!
        if(v == -1){
            ts.remove(nnex)
        }else {
            ls[nnex].add(v)
        }
        cur = nnex
    }
    out.println(m)
    for(row in ls){
        out.print(row.size)
        for(x in row){
            out.print(" ")
            out.print(x)
        }
        out.println()
    }
}

val out = PrintWriter(System.out)

fun main(args: Array<String>) {
    solve()
    out.flush()
}

fun nline() = readLine()!!
fun ni() = nline().toInt()
fun nl() = nline().toLong()
fun nd() = nline().toDouble()
fun nas() = nline().split(" ")
fun na() = nas().map { it.toInt() }
fun nal() = nas().map { it.toLong() }

fun tr(x: Any) = System.err.println(x)
fun tr(x: IntArray) = System.err.println(Arrays.toString(x))
fun tr(x: Array<Any>) = System.err.println(Arrays.deepToString(x))