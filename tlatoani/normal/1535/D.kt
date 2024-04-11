fun main() {
    val k = readLine()!!.toInt()
    val s = (" " + readLine()!!.reversed()).toCharArray()
    val reachable = IntArray(1 shl k)
    for (j in s.lastIndex downTo 1) {
        val left = if (2 * j >= 1 shl k) 1 else reachable[2 * j]
        val right = if ((2 * j) + 1 >= 1 shl k) 1 else reachable[(2 * j) + 1]
        reachable[j] = when (s[j]) {
            '0' -> right
            '1' -> left
            else -> left + right
        }
    }
    val q = readLine()!!.toInt()
    val out = StringBuilder()
    repeat(q) {
        val (p, chara) = readLine()!!.split(" ")
        var j = (1 shl k) - p.toInt()
        s[j] = chara[0]
        while (j >= 1) {
            val left = if (2 * j >= 1 shl k) 1 else reachable[2 * j]
            val right = if ((2 * j) + 1 >= 1 shl k) 1 else reachable[(2 * j) + 1]
            reachable[j] = when (s[j]) {
                '0' -> right
                '1' -> left
                else -> left + right
            }
            j /= 2
        }
        out.appendln(reachable[1])
    }
    print(out)
}