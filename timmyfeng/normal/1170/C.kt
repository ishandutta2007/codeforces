fun main() {
    val k = readLine()!!.toInt()
    for (kk in 0 until k) {
        val s = readLine()!!
        val t = readLine()!!.toCharArray()
        var ok = true
        var j = 0
        for (i in s) {
            if (j >= t.size) {
                ok = false
                break
            }
            if (i != t[j]) {
                if (i == '-') {
                    t[j] = '-'
                } else {
                    ok = false
                    break
                }
            } else {
                ++j
            }
        }
        if (j < t.size) {
            ok = false
        }
        println(if (ok) "YES" else "NO")
    }
}