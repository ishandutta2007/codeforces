import org.w3c.dom.ranges.Range

fun main() {
    val (n,m) = readv()
    val a = List(n) {readv()}

    var b = MutableList(n) {MutableList(m) {0} }
    var ans = MutableList<Pair<Int, Int>> (0) {Pair(0,0)}
    for (i in 0..n-2) for(j in 0..m-2) {
        if(a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1) {
            b[i][j] = 1
            b[i+1][j] = 1
            b[i][j+1] = 1
            b[i+1][j+1] = 1
            ans.add(Pair(i+1, j+1))
        }
    }
    if(a==b) {
        println(ans.size)
        println(ans.joinToString("\n") {"${it.first} ${it.second}"})
    }
    else println(-1)
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}