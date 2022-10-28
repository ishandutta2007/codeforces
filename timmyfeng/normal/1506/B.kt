fun main() {
    val t = readLine()!!.toInt()
    for (i in 0 until t) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val s = readLine()!!

        val stars = mutableListOf<Int>()
        for (i in 0 until n) {
            if (s[i] == '*') {
                stars.add(i)
            }
        }

        var i = 0
        var ans = 1
        while (i < stars.size - 1) {
            var j = i
            while (j < stars.size && stars[j] - stars[i] <= k) {
                ++j
            }
            i = j - 1
            ++ans
        }

        println(ans)
    }
}