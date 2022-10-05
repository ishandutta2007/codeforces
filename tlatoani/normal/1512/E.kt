fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var (n, l, r, s) = readLine()!!.split(" ").map { it.toInt() }
        var d = r - l + 1
        if (s in (d * (d + 1)) / 2..((n * (n + 1)) / 2) - (((n - d) * (n - d + 1)) / 2)) {
            val inside = mutableListOf<Int>()
            for (k in n downTo 1) {
                if (s - k >= (d * (d - 1)) / 2) {
                    inside.add(k)
                    s -= k
                    d--
                    if (d == 0) {
                        break
                    }
                }
            }
            val all = (1..n).toMutableList()
            all.removeAll(inside)
            val answer = all.subList(0, l - 1) + inside + all.subList(l - 1, all.size)
            println(answer.joinToString(" "))
        } else {
            println(-1)
        }
    }
}