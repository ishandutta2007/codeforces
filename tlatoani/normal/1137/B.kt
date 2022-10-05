val MOD1 = 1000000007L
val P1 = 3L
val MOD2 = 998244353L
val P2 = 5L

fun main() {
    val s = readLine()!!
    val t = readLine()!!
    var mostIntersection = 0
    var prefixHash1 = 0L
    var suffixHash1 = 0L
    var pow1 = 1L
    var prefixHash2 = 0L
    var suffixHash2 = 0L
    var pow2 = 1L
    for (j in 1 until t.length) {
        prefixHash1 += pow1 * (t[j - 1] - '0').toLong()
        prefixHash1 %= MOD1
        suffixHash1 *= P1
        suffixHash1 += (t[t.length - j] - '0').toLong()
        suffixHash1 %= MOD1
        prefixHash2 += pow2 * (t[j - 1] - '0').toLong()
        prefixHash2 %= MOD2
        suffixHash2 *= P2
        suffixHash2 += (t[t.length - j] - '0').toLong()
        suffixHash2 %= MOD2
        if (prefixHash1 == suffixHash1 && prefixHash2 == suffixHash2) {
            mostIntersection = j
        }
        pow1 *= P1
        pow1 %= MOD1
        pow2 *= P2
        pow2 %= MOD2
    }
    val initial0 = t.count { it == '0' }
    val initial1 = t.count { it == '1' }
    val remT = t.substring(mostIntersection)
    val addend0 = remT.count { it == '0' }
    val addend1 = remT.count { it == '1' }
    var s0 = s.count { it == '0' }
    var s1 = s.count { it == '1' }
    if (initial0 > s0 || initial1 > s1) {
        println(s)
        return
    }
    val out = StringBuilder()
    out.append(t)
    s0 -= initial0
    s1 -= initial1
    while (s0 >= addend0 && s1 >= addend1) {
        s0 -= addend0
        s1 -= addend1
        out.append(remT)
    }
    for (j in 1..s0) {
        out.append('0')
    }
    for (j in 1..s1) {
        out.append('1')
    }
    println(out)
}