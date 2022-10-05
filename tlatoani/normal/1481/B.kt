fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val hs = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
        var answer = 0
        for (a in 1..k) {
            var j = 0
            while (j < n - 1 && hs[j] >= hs[j + 1]) {
                j++
            }
            if (j == n - 1) {
                answer = -1
                break
            }
            hs[j]++
            answer = j + 1
        }
        println(answer)
    }
}