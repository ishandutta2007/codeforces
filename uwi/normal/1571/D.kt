//package kh8
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

class D {
    fun solve() {
        var (n, m) = na()
        var fls = mutableListOf<List<Int>>()
        for(i in 0..m-1){
            fls.add(na())
        }
        var f = mutableListOf<IntArray>()
        for(i in 0..n){
            f.add(IntArray(n+1))
        }
        var f1 = IntArray(n+1)
        var f2 = IntArray(n+1)
        for(i in 1..m-1){
            f1[fls[i][0]]++
            f2[fls[i][1]]++
            f[fls[i][0]][fls[i][1]]++
        }
        var rank = 1
        for(i in 1..n){
            for(j in 1..n){
                if(i == j)continue
                var sc = 0
                if(fls[0][0] == i){
                    sc++
                }
                if(fls[0][1] == j){
                    sc++
                }
                if(sc == 2){
                    rank = Math.max(rank, 1)
                }else if(sc == 1){
                    rank = Math.max(rank, f[i][j] + 1)
                }else{
                    rank = Math.max(rank, f1[i] + f2[j] - f[i][j] + 1)
                }
            }
        }
        out.println(rank)
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
fun main() = D().run()