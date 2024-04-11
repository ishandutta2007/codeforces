fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        val a = line.substring(0, six).toLong()
        var m = line.substring(six + 1).toLong()
        var alpha = m
        var beta = a
        while (beta != 0L) {
            alpha %= beta
            val gamma = alpha
            alpha = beta
            beta = gamma
        }
        m /= alpha
        var totient = 1L
        for (p in 2L..100000L) {
            if (m % p == 0L) {
                while (m % p == 0L) {
                    m /= p
                    totient *= p
                }
                totient /= p
                totient *= p - 1L
            }
        }
        if (m != 1L) {
            totient *= m - 1L
        }
        println(totient)
    }
}