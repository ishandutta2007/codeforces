fun main() {
    val out = StringBuilder()
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!.split(" ")
        val n = line[0].toInt()
        val m = line[1].toInt()
        val a = line[2].toInt()
        val b = line[3].toInt()
        if (n * a == m * b) {
            out.appendln("YES")
            for (y in 0 until n) {
                val row = CharArray(m) { '0' }
                for (x in 0 until a) {
                    row[((y * a) + x) % m] = '1'
                }
                out.appendln(row)
            }
        } else {
            out.appendln("NO")
        }
    }
    print(out)
}