fun main() {
    val n = readLine()!!.toInt()
    fun query(a: Int): List<Int> {
        println("? ${a + 1}")
        return readLine()!!.split(" ").map { it.toInt() }
    }
    val query0 = query(0)
    val amtEven = query0.count { it % 2 == 0 }
    val out = StringBuilder()
    val parity = if (amtEven <= (n + 1) / 2) 0 else 1
    for (a in 0 until n) {
        if (query0[a] % 2 == parity) {
            val query = if (a == 0) query0 else query(a)
            for (b in 0 until n) {
                if (query[b] == 1) {
                    out.appendln("${a + 1} ${b + 1}")
                }
            }
        }
    }
    println("!")
    print(out)
}