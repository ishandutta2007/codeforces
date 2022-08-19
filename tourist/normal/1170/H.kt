fun main(args: Array<String>) {
    val tt = readLine()!!.toInt()
    var res = Array<String>(tt, {i -> ""})
    for (qq in 0..tt-1) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }
        var b: MutableList<Int> = mutableListOf()
        for (c in a) {
            b.add(c)
        }
        b.sort()
        var mx = -1
        var who = -1
        var beg = 0
        while (beg < n) {
            var end = beg
            while (end + 1 < n && b[end + 1] == b[end]) end++
            var occ = end - beg + 1
            if (occ > mx) {
                mx = occ
                who = b[beg]
            }
            beg = end + 1
        }
        var rest = n - mx
        if (mx > rest) {
            mx = rest
            if (who == b[0] || who == b.last()) {
                mx++
            }
        } else {
            mx = -1
            who = -1
        }
        var d: MutableList<Int> = mutableListOf()
        if (who != -1) {
            for (i in 0 until mx) {
                d.add(who)
            }
        }
        for (c in b) {
            if (c != who) {
                d.add(c)
            }
        }
        d.sort()
        var e: MutableList<Int> = mutableListOf()
        if (d.size % 2 == 0) {
            for (i in 0 until (d.size / 2)) {
                e.add(d[d.size / 2 - 1 - i])
                e.add(d[d.size - 1 - i])
            }
        } else {
            e.add(d[d.size / 2])
            if (d[0] == d[d.size / 2]) {
                for (i in 0 until (d.size / 2)) {
                    e.add(d[d.size - 1 - i])
                    e.add(d[d.size / 2 - 1 - i])
                }
            } else {
                for (i in 0 until (d.size / 2)) {
                    e.add(d[i])
                    e.add(d[d.size / 2 + 1 + i])
                }
            }
        }
        res[qq] = (e.size).toString() + "\n" + e.joinToString(" ")
    }
    println(res.joinToString("\n"))
}