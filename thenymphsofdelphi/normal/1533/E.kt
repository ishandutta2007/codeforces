import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
    val n = readInt()
    var cac = readInts()
    val a = IntArray(n)
    for (i in 0..n-1){
        a[i] = cac[i]
    }
    a.sort()
    cac = readInts()
    val b = IntArray(n + 1)
    for (i in 0..n){
        b[i] = cac[i]
    }
    b.sort()
    val pref = IntArray(n + 1)
    val suff = IntArray(n + 1)
    pref[0] = b[0] - a[0]
    for (i in 1..n-1){
        pref[i] = max(pref[i - 1], b[i] - a[i])
    }
    suff[n] = b[n] - a[n - 1]
    for (i in n-1 downTo 1){
        suff[i] = max(suff[i + 1], b[i] - a[i - 1])
    }
    val q = readInt()
    val c = readInts()
    val ans = IntArray(q)
    for (qq in 0..q-1){
        var lo = 0
        var hi = n
        while (lo < hi){
            val mid = (lo + hi) / 2
            if (a[mid] >= c[qq]){
                hi = mid
            }
            else{
                lo = mid + 1
            }
        }
        ans[qq] = b[lo] - c[qq]
        if (lo > 0){
            ans[qq] = max(ans[qq], pref[lo - 1])
        }
        if (lo < n){
            ans[qq] = max(ans[qq], suff[lo + 1])
        }
    }
    println(ans.joinToString(separator = " "))
}