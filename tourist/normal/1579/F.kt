fun main() {
    val t = readInt()
    repeat(t) {
        val (n, d) = readInts()
        val a = readInts()
        val seen = BooleanArray(n)
        var ans = 0
        for (i in 0 until n) {
            if (seen[i]) {
                continue
            }
            val b = ArrayList<Int>()
            var j = i
            while (!seen[j]) {
                b.add(a[j])
                seen[j] = true
                j = (j + d) % n
            }
            var cur = 0
            var max = 0
            for (t in 0 until 2 * b.size) {
                if (b[t % b.size] == 1) {
                    cur += 1
                } else {
                    cur = 0
                }
                max = maxOf(max, cur)
            }
            if (max >= b.size) {
                ans = -1
                break
            }
            ans = maxOf(ans, max)
        }
        println(ans)
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }