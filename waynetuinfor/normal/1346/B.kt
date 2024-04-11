import java.util.*

fun main() {
    var t = readLine()!!.toInt()
    while (t-- > 0) {
        var (n, k1, k2) = readLine()!!.split(" ").map{ it.toInt() }
        val s = readLine()!!
        var i = 0
        var res: Long = 0
        k2 = k2 - k1
        if (k2 > k1) {
            k2 = k1
        }
        if (k1 > k2) {
            k1 = k2.also { k2 = k1 }
        }
        while (i < n) {
            if (s[i] == '0') {
                i += 1
                continue
            }
            var j = i
            while (j < n && s[j] == '1') j += 1
            val k = j - i
            if (k % 2 == 0) {
                res += (k1 + k2) * (k / 2)
            } else {
                res += k1 * (k / 2) + k2 * (k / 2 + 1)
            }
            i = j
        }
        println(res)
    }
}