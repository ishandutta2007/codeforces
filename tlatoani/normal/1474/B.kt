fun main() {
    val isPrime = BooleanArray(100002) { true }
    val nextPrime = IntArray(100002)
    for (p in 2..100000) {
        if (isPrime[p]) {
            for (k in 2 * p..100000 step p) {
                isPrime[k] = false
            }
        }
    }
    isPrime[1] = false
    for (k in 100000 downTo 1) {
        nextPrime[k] = if (isPrime[k]) {
            k
        } else {
            nextPrime[k + 1]
        }
    }
    for (c in 1..readLine()!!.toInt()) {
        val d = readLine()!!.toInt()
        val p = nextPrime[d + 1]
        val q = nextPrime[p + d]
        println(p * q)
    }
}