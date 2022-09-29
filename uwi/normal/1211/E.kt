import java.io.PrintWriter
import java.util.*

fun ok(h:Int, a: List<Int>): Boolean {
    var f = IntArray(h+1)
    var first: MutableList<Int> = mutableListOf()
    var second: MutableList<Int> = mutableListOf()
    for(u in a){
        if(u <= h){
            f[u]++
            if(f[u] == 1){
                first.add(u)
            }else if(f[u] == 2){
                second.add(u)
            }else{
                return false
            }
        }
    }
    if(first.size < h)return false
    if(second.size < h)return false
    return first.equals(second)
}

fun solve() {
    val n = ni()
    var a = na()

    var low = 0
    var high = n+1
    while(high - low > 1){
        var h = high+low shr 1
        if(ok(h, a)){
            low = h
        }else{
            high = h
        }
    }

    var rems = IntArray(200005)
    for(i in 1..low){
        rems[i] = 2
    }

    for(v in a){
        out.print("BGR"[rems[v]])
        if(rems[v] > 0){
            rems[v]--
        }
    }
    out.println()
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