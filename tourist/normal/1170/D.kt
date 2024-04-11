fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }
    var m = 0
    for (c in a) {
        if (c == -1) m++
    }
    println(m)
    var b = Array<MutableList<Int>>(m, { i -> mutableListOf() })
    var pr = IntArray(m, {i -> if (i > 0) i - 1 else m - 1})
    var ne = IntArray(m, {i -> if (i < m - 1) i + 1 else 0})
    var cur = 0
    for (c in a) {
        if (c == -1) {
            pr[ne[cur]] = pr[cur]
            ne[pr[cur]] = ne[cur]
        } else {
            b[cur].add(c)
        }
        cur = ne[cur]
    }
    var s = Array<String>(m, { i -> "" })
    for (i in 0 until m) {
        s[i] = b[i].size.toString() + " " + b[i].joinToString(" ")
    }
    println(s.joinToString("\n"))
}