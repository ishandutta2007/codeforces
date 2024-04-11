import java.io.PrintWriter
import java.util.*

fun solve() {
    val (n, m) = na()
    var ini = mutableListOf<IntArray>()
    var end = mutableListOf<IntArray>()
    for(i in 1..n){
        ini.add(na().toIntArray())
    }
    for(i in 1..m){
        end.add(na().toIntArray())
    }

    var map0: HashMap<Int, TreeSet<Int>> = hashMapOf()
    var map1: HashMap<Int, TreeSet<Int>> = hashMapOf()
    for(e in end){
        val key = e[0]+e[1]
        if((e[1] - e[0]) % 2 == 0) {
            if (!map0.containsKey(key)) {
                map0.put(key, sortedSetOf())
            }
            map0[key]!!.add(e[1] - e[0])
        }else{
            if (!map1.containsKey(key)) {
                map1.put(key, sortedSetOf())
            }
            map1[key]!!.add(e[1] - e[0])
        }
    }

    for(u in ini){
        val key = u[0]+u[1]
        var map: HashMap<Int, TreeSet<Int>> = if((u[1] - u[0]) % 2 == 0) map0 else map1
        var done: Int = -1
        if (map.containsKey(key)) {
            val en = map[key]!!.floor(u[1] - u[0])
            if (en != null) {
                done = (u[1] - u[0] - en) / 2
            }
        }
        val keyp = u[0]+u[1]+2
        val keym = u[0]+u[1]-2
        if(map.containsKey(keyp) && map.containsKey(keym)){
            val en1 = map[keyp]!!.floor(u[1] - u[0] - 2)
            val en2 = map[keym]!!.floor(u[1] - u[0] - 2)
            if(en1 != null && en2 != null){
                val can = (u[1] - u[0] - Math.min(en1, en2)) / 2
                if(done == -1 || can < done){
                    done = can
                }
            }
        }
        out.print(done)
        out.print(" ")
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