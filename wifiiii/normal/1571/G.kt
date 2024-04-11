import java.lang.Math.*
import java.util.*

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { kotlin.system.exitProcess(0); }

val maxn = 300055
var mx = LongArray(maxn)
fun add(x: Int, v: Long) {
    var x = x + 1
    while (x < maxn) {
        mx[x] = max(mx[x], v)
        x += x and -x
    }
}
fun qry(x: Int) : Long {
    var x = x + 1
    var ans = 0L
    while (x > 0) {
        ans = max(ans, mx[x])
        x -= x and -x
    }
    return ans
}

class node(val a: Int, var b: Int, var c: Int): Comparable<node> {
    override fun compareTo(other: node): Int {
        if(this.a != other.a) {
            return compareValues(this.a, other.a);
        }
        return compareValues(this.b, other.b);
    }
}

fun main() {
    var (n, m) = readii()
    var a = ArrayList<node>()
    for (r in 1..n) {
        var k = readi()
        var w = readii().toIntArray()
        var b = readii().toIntArray()
        for (i in 0..k-1) {
            b[i] = m - b[i]
            if(b[i] >= 0 && r - b[i] > 0) {
                a.add(node(b[i], r - b[i], w[i]))
            }
            // (a[i], i - a[i])
        }
    }
    a.sort()
    var ans = 0L
    for (i in 0..a.size-1) {
        var x = a[i].b
        var y = a[i].c
        val tmp = qry(x - 1)
        ans = max(ans, tmp + y)
        add(x, tmp + y)
    }
    println(ans)
}