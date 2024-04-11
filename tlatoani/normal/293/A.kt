fun main() {
    val n = readLine()!!.toInt()
    val amts = Array(2) { IntArray(2) }
    val s = readLine()!!
    val t = readLine()!!
    for (j in 0 until 2 * n) {
        amts[s[j] - '0'][t[j] - '0']++
    }
    val res1 = mutableListOf<Int>()
    val res2 = mutableListOf<Int>()
    for (j in 0 until 2 * n) {
        if (j % 2 == 0) {
            if (amts[1][1] > 0) {
                res1.add(1)
                amts[1][1]--
            } else if (amts[1][0] > 0) {
                res1.add(1)
                amts[1][0]--
            } else if (amts[0][1] > 0) {
                res1.add(0)
                amts[0][1]--
            } else {
                res1.add(0)
                amts[0][0]--
            }
        } else {
            if (amts[1][1] > 0) {
                res2.add(1)
                amts[1][1]--
            } else if (amts[0][1] > 0) {
                res2.add(1)
                amts[0][1]--
            } else if (amts[1][0] > 0) {
                res2.add(0)
                amts[1][0]--
            } else {
                res2.add(0)
                amts[0][0]--
            }
        }
    }
    res1.sortDescending()
    res2.sortDescending()
    for (j in 0 until n) {
        if (res1[j] > res2[j]) {
            println("First")
            return
        } else if (res2[j] > res1[j]) {
            println("Second")
            return
        }
    }
    println("Draw")
}