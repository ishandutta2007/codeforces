import java.util.*
import kotlin.collections.HashSet
import kotlin.math.abs
import kotlin.math.min
import kotlin.math.max
import kotlin.system.exitProcess

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { exitProcess(0); }


class pair(val a: Int, var b: Int): Comparable<pair> {
    override fun compareTo(other: pair): Int {
        if(this.a != other.a) {
            return other.a - this.a
        }
        return other.b - this.b
    }
}

var d = IntArray(100005)
fun main() {
    var n = readi()
    for(i in 1..n) {
        for(j in i+i..n step i) {
            d[j] += 1
        }
    }
    var vis = IntArray(n+1)
    var s = TreeSet<pair>()
    for (i in 1..n) {
        s.add(pair(-d[i], -i))
    }
    var ans = 0
    for (i in 0 until n) {
        val cur = s.last()
        s.remove(cur)
        var dd = -cur.a
        ans += dd
        var ii = -cur.b
        vis[ii] = 1
        for (j in ii+ii..n step ii) {
            if(vis[j] == 1) {
                continue
            }
            s.remove(pair(-d[j], -j))
            d[j] -= 1
            s.add(pair(-d[j], -j))
        }
        var j = 1
        while(j * j <= ii) {
            if(ii % j == 0) {
                if(vis[j] == 0) {
                    s.remove(pair(-d[j], -j))
                    d[j] -= 1
                    s.add(pair(-d[j], -j))
                }
                if(vis[ii / j] == 0) {
                    if(j * j != ii) {
                        s.remove(pair(-d[ii / j], -ii / j))
                        d[ii / j] -= 1
                        s.add(pair(-d[ii / j], -ii / j))
                    }
                }
            }
            j += 1
        }
        print("${ans} ")
    }
}