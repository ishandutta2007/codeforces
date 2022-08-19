fun main(args: Array<String>) {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    var a = readLine()!!.split(" ").map { it.toInt() }
    var b: MutableList<Int> = mutableListOf(0)
    for (c in a) {
        b.add(b.last() + c)
    }
    var tt = readLine()!!.toInt()
    var res = Array<String>(tt, {i -> ""})
    for (qq in 0..tt-1) {
        var w = (readLine()!! + " " + (m + 1).toString()).split(" ").map { it.toInt() }
        var first = 1
        var last = 0
        var i = 0
        for (c in w) {
            if (first == 1) {
                first = 0
                continue
            }
            val space = c - last - 1
            var low = i
            var high = n
            while (low < high) {
                var mid = (low + high + 1) shr 1
                if (b[mid] - b[i] <= space) {
                    low = mid
                } else {
                    high = mid - 1
                }
            }
            i = low
            last = c
        }
        res[qq] = (if (i == n) "YES" else "NO")
    }
    println(res.joinToString("\n"))
}