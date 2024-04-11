fun main() {
    val primes = (2..1000).filter { p -> (2 until p).all { q -> p % q != 0 } }
    val (nOrig, mOrig) = readLine()!!.split(" ").map { it.toInt() }
    var (n, m) = Pair(nOrig, mOrig)
    fun query(h: Int, w: Int, y1: Int, x1: Int, y2: Int, x2: Int): Boolean {
        println("? $h $w ${y1 + 1} ${x1 + 1} ${y2 + 1} ${x2 + 1}")
        return readLine() == "1"
    }
    for (p in primes) {
        while (n % p == 0) {
            var works = true
            var e = 0
            while (1 shl (e + 1) < p) {
                works = works && query((1 shl e) * (n / p), m, 0, 0, (1 shl e) * (n / p), 0)
                e++
            }
            val f = p - (1 shl e)
            works = works && query(f * (n / p), m, 0, 0, (p - f) * (n / p), 0)
            if (works) {
                n /= p
            } else {
                break
            }
        }
    }
    for (p in primes) {
        while (m % p == 0) {
            var works = true
            var e = 0
            while (1 shl (e + 1) < p) {
                works = works && query(n, (1 shl e) * (m / p), 0, 0, 0, (1 shl e) * (m / p))
                e++
            }
            val f = p - (1 shl e)
            works = works && query(n, f * (m / p), 0, 0, 0, (p - f) * (m / p))
            if (works) {
                m /= p
            } else {
                break
            }
        }
    }
    var nFactors = (1..1000).count { (nOrig / n) % it == 0 }
    var mFactors = (1..1000).count { (mOrig / m) % it == 0 }
    println("! ${nFactors * mFactors}")
}