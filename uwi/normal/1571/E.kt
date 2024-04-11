//package kh8
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class E {
    fun solve() {
        repeat(ni()) { go() }
    }

    fun go() {
        var n = ni()
        var s = nline()
        var a = nline()
        var t = StringBuilder(s)
//        var u = IntArray(n)
        for(i in 0..n-4){
            if(a[i] == '1'){
                t[i] = '('
                t[i+1] = ')'
                t[i+2] = '('
                t[i+3] = ')'
//                u[i] = 1
//                u[i+1] = 1
//                u[i+2] = 1
//                u[i+3] = 1
            }
        }
        for(i in 0..n-4){
            if(a[i] == '1'){
                if(t[i] != '(' || t[i+1] != ')' || t[i+2] != '(' || t[i+3] != ')'){
                    out.println(-1)
                    return
                }
            }
        }

        var ans = 0
//        var h = 0
//        for(i in 0..n-1){
//            if(t[i] == '('){
//                h++
//            }else{
//                h--
//                if(h < 0 && u[i] == 0){
//                    ans++
//                    h += 2
//                }
//            }
//            if(h < 0){
//                out.println(-1);
//                return
//            }
//        }
//        if(h > 0){
//            for(i in n-1 downTo 0){
//                if(t[i] == '(' && u[i] == 0){
//                    h -= 2
//                    ans++
//                    if(h == 0)break
//                }
//            }
//            if(h > 0){
//                out.println(-1)
//                return
//            }
//        }
        var i = 0
        while(i < n-3){
            if(a[i] == '1'){
                var j = i
                while(j < n-3 && a[j] == '1'){
                    j += 2
                }
                if(j > i+2){
                    var cost1 = 0
                    for(k in i..j+1) {
                        if ((k - i) % 2 == 0) {
                            if (s[k] != '(') cost1++
                        } else {
                            if (s[k] != ')') cost1++
                        }
                    }
                    ans += cost1
                    i = j + 1
                }else{
                    var cost1 = 0
                    if(s[i] != '(')cost1++
                    if(s[i+1] != ')')cost1++
                    if(s[i+2] != '(')cost1++
                    if(s[i+3] != ')')cost1++
                    var cost2 = 0
                    if(s[i] != '(')cost2++
                    if(s[i+1] != '(')cost2++
                    if(s[i+2] != ')')cost2++
                    if(s[i+3] != ')')cost2++
                    ans += Math.min(cost1, cost2)
                    i += 1
                }
            }else{
                i++
            }
        }
        out.println(ans)
    }

    val out = PrintWriter(System.out)

    fun run() {
        tr(measureTimeMillis {
            solve()
            out.flush()
        })
    }

    fun nline() = readLine()!!
    fun ni() = nline().toInt()
    fun nl() = nline().toLong()
    fun nd() = nline().toDouble()
    fun nas() = nline().split(" ")
    fun na() = nas().map { it.toInt() }
    fun nal() = nas().map { it.toLong() }

    fun tr(vararg x: Any) = System.err.println(Arrays.deepToString(x))
}

// TODO
fun main() = E().run()