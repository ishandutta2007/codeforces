var cnt = Array(1000, {Array(1000, {0})})
var cf = Array(1000, {0})
var cl = Array(1000, {0})
fun main() {
    var (n,m) = readv()
    var (a,b) = readv()
    a--
    b--
    repeat(m-1) {
        var (v, u) = readv()
        v--
        u--
        cf[v]++
        cl[u]++
        cnt[v][u]++
    }
    var worst = 1
    for(i in 0 until n) for(j in 0 until n) {
        if(i==j) continue
        if(i == a && j == b) continue
        else if(i==a || j==b) {
            worst = maxOf(worst, 1+cnt[i][j])
        }
        else {
            worst = maxOf(worst, 1 + cf[i] + cl[j] - cnt[i][j])
        }
    }
    println(worst)
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}