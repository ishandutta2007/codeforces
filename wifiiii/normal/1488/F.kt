import java.util.*
import kotlin.collections.ArrayList
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

var stk = IntArray(200005)
var cnt = IntArray(200005)
var w = LongArray(200005)
var idx = IntArray(200005)
var pre = LongArray(200005)
var ans = LongArray(200005)

fun main() {
    var tp = 0
    var n = readi()
    var a = readii()
    var q = readi()
    var qrys = ArrayList<ArrayList<Pair<Int,Int>>>()
    for (i in 0..n) qrys.add(ArrayList<Pair<Int,Int>>())
    for (ca in 0 until q) {
        var (l, r) = readii()
        qrys[r].add(Pair<Int,Int>(l, ca))
    }
    for (i in 1..n) {
        var x = a[i-1]
        var tmp = 0L + x
        var tmp3 = 1
        while(tp > 0 && stk[tp] <= x) {
            tmp3 += cnt[tp]
            tp -= 1
        }
//        println("${i} tp: ${tp}")
        tp += 1
        stk[tp] = x
        w[tp] = 1L * tmp3 * x
        cnt[tp] = tmp3
        pre[tp] = pre[tp-1] + w[tp]
        idx[tp] = i
//        for(j in 0..tp) print("${stk[j]} "); println("")
//        for(j in 0..tp) print("${w[j]} "); println("")
//        for(j in 0..tp) print("${pre[j]} "); println("")
//        for(j in 0..tp) print("${idx[j]} "); println("")
        for ((l, ca) in qrys[i]) {
            var lo = 0
            var hi = tp - 1
            // make idx[lo] < l
            while(lo < hi) {
                var mid = (lo + hi + 1) / 2
                if (idx[mid] >= l) hi = mid - 1;
                else lo = mid
            }
            var tmp2 = pre[tp] - pre[lo]
            tmp2 -= 1L * (l - idx[lo] - 1) * stk[lo + 1]
            ans[ca] = tmp2
        }
    }
    for (i in 0 until q) {
        print("${ans[i]} ")
    }
}