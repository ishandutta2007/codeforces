import java.io.PrintWriter
import java.util.*

var fs: LongArray = LongArray(21)

fun solve() {
    fs[0] = 1
    for(i in 1..20){
        fs[i] = fs[i-1] * i
    }

    var(m, K) = na()
    var KK: Long = K.toLong()
    val ps = intArrayOf(2, 3, 5, 7)
    var es = IntArray(10)
    for(p in ps){
        while(m % p == 0){
            m /= p
            es[p] += 1
        }
    }
    if(m > 1){
        out.println(-1)
        return
    }

    KK -= 1
    for(d in 1..100000){
        val all = count1(d, es)
        if(KK >= all){
            KK -= all
        }else{
            for(i in 0..d-1){
                for(t in 1..9){
                    if(t == 2){
                        if(es[2] < 1)continue
                        es[2] -= 1
                    }else if(t == 4){
                        if(es[2] < 2)continue
                        es[2] -= 2
                    }else if(t == 8){
                        if(es[2] < 3)continue
                        es[2] -= 3
                    }else if(t == 3){
                        if(es[3] < 1)continue
                        es[3] -= 1
                    }else if(t == 9){
                        if(es[3] < 2)continue
                        es[3] -= 2
                    }else if(t == 5){
                        if(es[5] < 1)continue
                        es[5] -= 1
                    }else if(t == 7){
                        if(es[7] < 1)continue
                        es[7] -= 1
                    }else if(t == 6){
                        if(es[2] < 1 || es[3] < 1)continue
                        es[2] -= 1
                        es[3] -= 1
                    }

                    val lall = count1(d-i-1, es)
                    if(KK >= lall){
                        KK -= lall
                    }else{
                        out.print(t)
                        break
                    }

                    if(t == 2){
                        es[2] += 1
                    }else if(t == 4){
                        es[2] += 2
                    }else if(t == 8){
                        es[2] += 3
                    }else if(t == 3){
                        es[3] += 1
                    }else if(t == 9){
                        es[3] += 2
                    }else if(t == 5){
                        es[5] += 1
                    }else if(t == 7){
                        es[7] += 1
                    }else if(t == 6){
                        es[2] += 1
                        es[3] += 1
                    }
                    
                }
            }
            out.println()
            return
        }
    }
}

fun count1(d: Int, es: IntArray): Long {
    var ret: Long = 0
    for(six in 0..Math.min(es[2], es[3])){
        var two = es[2] - six
        var three = es[3] - six
        var five = es[5]
        var seven = es[7]
        for(eight in 0..two/3){
            for(four in 0..(two-eight*3)/2){
                for(nine in 0..three/2){
                    ret += count(d, two-2*four-3*eight, three-2*nine, four, five, six, seven, eight, nine)
                }
            }
        }
    }
    return ret
}

fun count(d: Int, vararg values: Int): Long {
    var s = d
    for(e in values){
        s -= e
    }
    if(s < 0)return 0
    var ret = 1L
    for(k in s+1..d){
        ret *= k
    }
    for(e in values){
        ret /= fs[e]
    }
    return ret
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