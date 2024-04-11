fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        val ys = readLine()!!.split(" ").map { it.toInt() }
        val ps = IntArray(n + 1)
        for (j in 0 until n) {
            ps[xs[j]] = ys[j]
        }
        var oddAMT = 0L
        val seen = BooleanArray(n + 1)
        for (r in 1..n) {
            if (!seen[r]) {
                var k = r
                var odd = false
                while (!seen[k]) {
                    seen[k] = true
                    odd = !odd
                    k = ps[k]
                }
                if (odd) {
                    oddAMT++
                }
            }
        }
        val eachHalf = (n.toLong() - oddAMT) / 2L
        val answer = 2L * (eachHalf + oddAMT) * eachHalf
        println(answer)
    }
}