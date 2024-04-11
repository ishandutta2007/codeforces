import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
    val s = readLn()
    val n = s.length
    val pref0 = IntArray(n + 1)
    val pref1 = IntArray(n + 1)
    for (i in 1..n){
        pref0[i] = pref0[i - 1]
        pref1[i] = pref1[i - 1]
        if (s[i - 1] == '0'){
            pref0[i]++
        }
        else{
            pref1[i]++
        }
    }
    val ans = IntArray(n)
    for (k in 1..n){
        var pos = 0
        while (pos < n){
            ans[k - 1]++
            var lo = pos + 1
            var hi = n
            while (lo < hi){
                val mid = (lo + hi + 1) / 2
                if (pref0[mid] - pref0[pos] <= k || pref1[mid] - pref1[pos] <= k){
                    lo = mid;
                }
                else{
                    hi = mid - 1
                }
            }
            pos = lo
        }
    }
    println(ans.joinToString(separator = " "))
}