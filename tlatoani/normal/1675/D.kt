fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val parent = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
        val r = (1..n).find { parent[it] == it }!!
        val child = IntArray(n + 1)
        for (a in 1..n) {
            if (a != r) {
                child[parent[a]] = a
            }
        }
        val paths = mutableListOf<List<Int>>()
        for (a in 1..n) {
            if (child[parent[a]] != a) {
                val path = mutableListOf<Int>()
                var a = a
                while (a != 0) {
                    path.add(a)
                    a = child[a]
                }
                paths.add(path)
            }
        }
        out.appendln(paths.size)
        for (path in paths) {
            out.appendln(path.size)
            out.appendln(path.joinToString(" "))
        }
    }
    print(out)
}