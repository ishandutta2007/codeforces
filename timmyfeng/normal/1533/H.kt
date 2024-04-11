fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val s = Array(n) { readLine()!!.map { it - 'A' } }

    val rect = LongArray(32)
    val ans = LongArray(5)

    for (k in 1 until 32) {
        val up = IntArray(m)
        val left = IntArray(m)

        for (i in 0 until n) {
            for (j in 0 until m) {
                up[j] = if ((k and (1 shl s[i][j])) > 0) up[j] + 1 else 0
            }

            val stack = mutableListOf<Int>()
            for (j in 0 until m) {
                while (stack.isNotEmpty() && up[stack.last()] >= up[j]) {
                    stack.removeLast()
                }
                left[j] = if (stack.isEmpty()) -1 else stack.last()
                stack.add(j)
            }

            stack.clear()
            for (j in m - 1 downTo 0) {
                while (stack.isNotEmpty() && up[stack.last()] > up[j]) {
                    stack.removeLast()
                }
                val right = if (stack.isEmpty()) m else stack.last()
                rect[k] = rect[k] + (j - left[j]) * (right - j) * up[j]
                stack.add(j)
            }
        }

        for (i in 1 until k) {
            if (i and k == i) {
                rect[k] -= rect[i]
            }
        }
        ans[k.countOneBits() - 1] = ans[k.countOneBits() - 1] + rect[k]
    }

    println(ans.joinToString(" "))
}