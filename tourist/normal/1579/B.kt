fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a = readInts().toIntArray()
        val res = mutableListOf<Step>()
        for (i in 0 until n) {
            var j = i
            for (k in j until n) {
                if (a[k] < a[j]) {
                    j = k
                }
            }
            if (i == j) {
                continue
            }
            res.add(Step(i, j, j - i))
            for (k in j downTo i+1) {
                a[k] = a[k - 1].also {a[k - 1] = a[k] }
            }
        }
        println(res.size)
        println(res.joinToString("\n") {"${it.l + 1} ${it.r + 1} ${it.d}"})
    }
}

data class Step(val l: Int, val r: Int, val d: Int)

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }