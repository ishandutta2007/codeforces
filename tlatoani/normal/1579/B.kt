fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        val indexes = ay.indices.sortedBy { ay[it] }
        var memory = ay.indices.toList()
        val out = StringBuilder()
        for (j in indexes) {
            if (memory.last() != j) {
                val x = memory.indexOf(j)
                out.appendln("${x + 1} $n 1")
                memory = memory.subList(0, x) + memory.subList(x + 1, n) + listOf(j)
            }
        }
        println(out.count { it == '\n' })
        print(out)
    }
}