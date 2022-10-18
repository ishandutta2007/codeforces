import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
    var (n, m) = readInts()
    val k = IntArray(n + 1); val t = IntArray(n + 1)
    val ans = IntArray(n + 1)
    var sumk = 0
    for (i in 1..n){
        val (tk, tt) = readInts()
        k[i] = tk; t[i] = tt;
        sumk += tk
    }
    if (sumk > m){
        println(-1)
        return
    }
    val prefk = IntArray(n + 1)
    for (i in 1..n){
        prefk[i] = prefk[i - 1]
        if (t[i] == 1){
            ans[i] = m - k[i] + 1
            m -= k[i]
        }
        else{
            prefk[i] += k[i]
        }
    }
    val dp = Array(n + 1){ Array(m + 1){ false } }
    dp[0][0] = true
    for (i in 1..n){
        if (t[i] == 1){
            for (j in 0..prefk[i]){
                dp[i][j] = dp[i - 1][j]
            }
        }
        else{
            for (j in 0..prefk[i]){
                dp[i][j] = dp[i - 1][j]
                if (j >= k[i] && dp[i - 1][j - k[i]] == true){
                    dp[i][j] = true
                }
            }
        }
    }
    var ansl = -1
    for (l in 0..prefk[n]){
        val r = prefk[n] - l
        if (dp[n][l] == true && l <= (m + 1) / 2 && r <= m / 2){
            ansl = l
            break
        }
    }
    if (ansl == -1){
        println(-1)
        return
    }
    var l = m; var r = m - 1
    for (i in n downTo 1){
        if (t[i] == 1){
            continue
        }
        if (dp[i - 1][ansl] == true){
            ans[i] = r - 2 * k[i] + 2
            r -= 2 * k[i]
        }
        else{
            ans[i] = l - 2 * k[i] + 2
            l -= 2 * k[i]
            ansl -= k[i]
        }
    }
    val tans = IntArray(n)
    for (i in 1..n){
        tans[i - 1] = ans[i]
    }
    println(tans.joinToString(separator = " "))
}