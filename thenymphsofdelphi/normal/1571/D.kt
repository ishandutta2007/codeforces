import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
    val (n, m) = readInts()
    val cnt = Array(n + 1){ IntArray(n + 1) }
    val cnt1 = IntArray(n + 1)
    val cnt2 = IntArray(n + 1)
    var ans = 0
    var fx = -1; var fy = -1
    repeat(m){
        val (x, y) = readInts()
        if (fx == -1){
            fx = x; fy = y;
        }
        cnt[x][y] += 1
        cnt1[x] += 1
        cnt2[y] += 1
    }
    for (i in 1..n){
        for (j in 1..n){
            if (i == j){
                continue
            }
            val c2 = cnt[i][j]
            val c1 = cnt1[i] + cnt2[j] - 2 * cnt[i][j]
            if (fx == i && fy == j){
                ans = max(ans, 1)
            }
            else if (fx == i || fy == j){
                ans = max(ans, c2 + 1)
            }
            else{
                ans = max(ans, c2 + c1 + 1)
            }
        }
    }
    println(ans)
}