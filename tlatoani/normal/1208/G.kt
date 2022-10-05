fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    if (k == 1) {
        println(3)
    } else {
        val totient = IntArray(n + 1)
        totient[1] = 1
        for (p in 1..n) {
            if (totient[p] == 0) {
                for (k in p..n step p) {
                    totient[k] = (if ((k / p) % p == 0) p else (p - 1)) * totient[k / p]
                }
            }
        }
        println(2 + totient.toList().subList(3, n + 1).sorted().subList(0, k).map { it.toLong() }.sum())
    }
}