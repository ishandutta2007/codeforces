fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a = readInts()
        val b = a.sorted().distinct()
        val f = IntArray(b.size)
        fun add(i: Int, v: Int) {
            var x = i
            while (x < b.size) {
                f[x] += v
                x = (x or (x + 1))
            }
        }
        fun sum(i: Int): Int {
            var x = i
            var s = 0
            while (x >= 0) {
                s += f[x]
                x = (x and (x + 1)) - 1
            }
            return s
        }
        var ans = 0L
        for (i in 0 until n) {
            val j = b.binarySearch(a[i])
            val c1 = sum(j - 1)
            val c2 = sum(b.size - 1) - sum(j)
            ans += minOf(c1, c2)
            add(j, 1)
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