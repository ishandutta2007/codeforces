fun main() {
    val n = read()
    var a = readv()
    var q : MutableList<Pair<Int, Int>>  = mutableListOf()
    for(i in 0..n-1) {
        q.add(Pair(a[i], i+1))
    }
    q.sortBy { -it.first }
    var res = 0
    for(i in 0..n-1) {
        res += q[i].first*i + 1
    }
    println(res)
    println((q.map {it.second}).joinToString(" "))
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}