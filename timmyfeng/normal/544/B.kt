fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    var l = 0

    if (k > (n * n + 1) / 2) {
        println("NO")
        return
    }

    println("YES")
    for (i in 0 until n) {
        for (j in 0 until n) {
            if ((i + j) % 2 == 0 && l < k) {
                print('L')
                ++l
            } else {
                print('S')
            }
        }
        println()
    }
}