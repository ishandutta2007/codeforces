import java.io.PrintWriter
import java.util.*


fun gcd(a: Int, b: Int): Int {
    var a = a
    var b = b
    while (b > 0) {
        val c = a
        a = b
        b = c % b
    }
    return a
}


//fun test(a: MutableList<Int>, ps: List<Int>): Pair<Boolean, Int> {
fun test(an: Int, ap: Int, ps: List<Int>): Pair<Boolean, Int> {
    if(an == 1){
        return true to ps[0]
    }
    var pe = 0
    for(p in ps){
        if(ap % p == 0){
            pe = p
            break
        }
    }
    if(pe == 0){
        return false to 0
    }
    return true to pe
}

fun solve() {
    val (n, m) = na()
    val ps = na()
    val xs = na()

    if(m == 2){
        out.println("YES")
        out.print(xs[0])
        out.print(" ")
        out.println(ps[0])
        out.print(xs[1])
        out.print(" ")
        out.println(ps[0])
        return
    }

    for(p in ps){
        if((xs[2]-xs[0]) % p == 0 ||
                (xs[1]-xs[0]) % p == 0 ||
                (xs[2]-xs[1]) % p == 0
                ){

            var rem0 = -1
            var remn = 0
            var remp = 0

            for(x in xs){
                if((x-xs[0]) % p != 0){
                    if(rem0 == -1){
                        rem0 = x
                    }
                    remn++
                    remp = gcd(remp, x-rem0)
                }
            }
            if(remn == 0) {
                out.println("YES")
                out.print(xs[0])
                out.print(" ")
                out.println(p)
                out.print(xs[0])
                out.print(" ")
                out.println(p)
                return
            }
            val (res, xp) = test(remn, remp, ps)
            if(res){
                out.println("YES")
                out.print(xs[0])
                out.print(" ")
                out.println(p)
                out.print(rem0)
                out.print(" ")
                out.println(xp)
                return
            }
        }
        if((xs[2]-xs[0]) % p == 0 ||
                (xs[1]-xs[0]) % p == 0 ||
                (xs[2]-xs[1]) % p == 0
        ){
            var first = -1
            for(x in xs){
                if ((x - xs[0]) % p != 0) {
                    first = x
                    break
                }
            }
            if(first != -1){
                var rem0 = -1
                var remn = 0
                var remp = 0

                for(x in xs){
                    if(x < first || (x-first) % p != 0){
                        if(rem0 == -1){
                            rem0 = x
                        }
                        remn++
                        remp = gcd(remp, x-rem0)
                    }
                }

                val (res, xp) = test(remn, remp, ps)
                if(res){
                    out.println("YES")
                    out.print(first)
                    out.print(" ")
                    out.println(p)
                    out.print(rem0)
                    out.print(" ")
                    out.println(xp)
                    return
                }
            }
        }
    }
    out.println("NO")
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
fun tr(x: Array<Any>) = System.err.println(Arrays.deepToString(x))