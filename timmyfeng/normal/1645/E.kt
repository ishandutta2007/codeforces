fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }

    var bit = n.takeHighestOneBit()
    val ans = mutableListOf<Int>()
    while (bit > 0) {
        if ((n and bit) > 0) ans.add(bit)
        bit /= 2
    }

    var i = 0
    while (i < ans.size) {
        while (ans[i] > 1 && ans.size < k) {
            ans.add(ans[i] / 2)
            ans[i] /= 2
        }
        ++i
    }

    if (ans.size != k) println("NO")
    else {
        println("YES")
        println(ans.joinToString(" "))
    }
}