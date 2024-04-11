fun main(args: Array<String>) {
    val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
    var a = readLine()!!.split(" ").map { it.toInt() }
    var b: MutableList<Int> = mutableListOf()
    for (c in a) {
        b.add(c)
    }
    b.sort()
    var p: MutableList<Long> = mutableListOf(0)
    for (c in b) {
        p.add(p.last() + c)
    }
    var ans: Long = 1000000000000000000L
    for (i in 0..n-m) {
        var low = i
        var high = i + (m / 2)
        while (low < high) {
            var mid = (low + high + 1) shr 1
            var ups = b[mid].toLong() * (mid - i + 1) - (p[mid + 1] - p[i])
            if (ups > k) {
                high = mid - 1
            } else {
                low = mid
            }
        }
        var ups = b[low].toLong() * (low - i + 1) - (p[low + 1] - p[i])
        var downs = (p[i + m] - p[low + 1]) - b[low].toLong() * (i + m - (low + 1))
        var cur = ups + downs
        var c0 = low - i + 1
        var c1 = i + m - (low + 1)
        if (c0 < c1) {
            var its = (k - ups) / c0
            cur -= (c1 - c0).toLong() * its
        }
        if (cur < ans) ans = cur
    }
    println(ans)
}