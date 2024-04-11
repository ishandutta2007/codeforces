fun main() {
    val pow27 = LongArray(11)
    pow27[0] = 1L
    for (j in 1..10) {
        pow27[j] = 27L * pow27[j - 1]
    }
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val strings = mutableSetOf<Long>()
    repeat(n) {
        val s = readLine()!!
        var hash = 0L
        for (j in 0 until m) {
            hash += pow27[j] * (s[j] - 'a' + 1).toLong()
        }
        strings.add(hash)
    }
    val q = readLine()!!.toInt()
    val out = StringBuilder()
    repeat(q) {
        val s = readLine()!!
        var answer = 0
        var hash = 0L
        for (j in 1..m) {
            hash += pow27[j - 1] * (s[j] - 'a' + 1).toLong()
        }
        val here = mutableSetOf<Long>()
        here.add(hash)
        for (j in 0 until m) {
            hash += pow27[j] * (s[j] - s[j + 1])
            here.add(hash)
        }
        out.appendln(here.count { it in strings })
    }
    print(out)
}