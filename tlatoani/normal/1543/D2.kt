fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        fun neg(x: IntArray) = IntArray(18) { (k - x[it]) % k }
        fun xor(x: IntArray, y: IntArray) = IntArray(18) { (x[it] + y[it]) % k }
        fun query(x: IntArray): Boolean {
            var xActual = 0
            for (j in 17 downTo 0) {
                xActual *= k
                xActual += x[j]
            }
            println(xActual)
            return readLine()!! == "1"
        }
        var currOffset = IntArray(18)
        var currActual = IntArray(18)
        for (j in 0 until n) {
            val q = xor(if (j % 2 == 0) currActual else neg(currActual), currOffset)
            if (query(q)) {
                break
            } else {
                currOffset = xor(q, neg(currOffset))
                for (j in 0..17) {
                    if (currActual[j] == k - 1) {
                        currActual[j] = 0
                    } else {
                        currActual[j]++
                        break
                    }
                }
            }
        }
    }
}