//package c

import java.io.PrintWriter
import java.util.*

fun solve() {
    val t = ni()
    for(z in 1..t){
        go()
    }
}

fun go() {
    val s = nline()
    val t = nline()
    var p = 0
    var q = 0
    while(p < s.length && q < t.length){
        if(t[q] == '-'){
            if(s[p] != '-'){
                out.println("NO")
                return
            }
            p++
            q++
        }else{
            if(s[p] == '+') {
                p++
                q++
            }else if(p+1 < s.length && s[p] == '-' && s[p+1] == '-'){
                p += 2
                q++
            }else{
                out.println("NO")
                return
            }
        }
    }
    if(p == s.length && q == t.length){
        out.println("YES")
    }else{
        out.println("NO")
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