val HASH_FUNCTIONS = listOf(
        Pair(960000947L, 571L),
        Pair(960002377L, 3929L),
        Pair(960000883L, 3967L),
        Pair(960001037L, 4447L)
)

fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val hashes = Array(4) { Array(n) { LongArray(1 shl n) } }
    for (m in hashes.indices) {
        val (mod, base) = HASH_FUNCTIONS[m]
        for ((j, letter) in s.withIndex()) {
            hashes[m][0][j] = (letter - 'a').toLong()
        }
        var pow = base
        for (d in 1 until n) {
            val bit = 1 shl (d - 1)
            for (mask in 0 until (1 shl n)) {
                val portion0 = hashes[m][d - 1][mask - (mask and bit)]
                val portion1 = hashes[m][d - 1][mask or bit]
                val (left, right) = if (mask and bit == 0) Pair(portion0, portion1) else Pair(portion1, portion0)
                hashes[m][d][mask] = (left + (pow * right)) % mod
            }
            pow = (pow * pow) % mod
        }
    }
    var best = 0
    for (x in 1 until (1 shl n)) {
        var j = 0
        for (d in n - 1 downTo 0) {
            var equal = true
            for (m in hashes.indices) {
                equal = equal && hashes[m][d][j xor best] == hashes[m][d][j xor x]
            }
            if (equal) {
                j += 1 shl d
            }
        }
        if (s[j xor x] < s[j xor best]) {
            best = x
        }
    }
    println(CharArray(1 shl n) { s[it xor best] })
}