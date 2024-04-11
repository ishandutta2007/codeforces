import java.util.*
import kotlin.math.*

fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun readdoubles() = ArrayList(readstrings().map { it.toDouble() })

fun main() {
    var tt=readint()
    while(tt-- > 0){
        var n=readint()
        var a=readints()
        var uf= dsu(n)
        for(i in 0..n-1){
            uf.unite(i,a[i]-1)
        }
        var ans=IntArray(n)
        for(i in 0..n-1){
            ans[i]=uf.sz[uf.get(i)]
        }
        println(ans.joinToString(" "))
    }
}

class dsu (n: Int) {
    var p = IntArray(n) { it }
    var sz = IntArray(n) { 1 }

    fun get (x: Int): Int {
        if (p[x] == x) {
            return x
        } else {
            p[x] = get(p[x])
            return p[x]
        }
    }
    fun unite (_x: Int, _y: Int) {
        var x = _x
        var y = _y
        x = get(x);
        y = get(y);
        if (x == y) {
            return
        }
        if (sz[x] > sz[y]) {
            p[y] = x
            sz[x] += sz[y]
        } else {
            p[x] = y
            sz[y] += sz[x]
        }
    }
    fun same (x: Int, y: Int): Boolean {
        return (get(x) == get(y))
    }
}