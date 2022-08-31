fun main(args: Array<String>) {
    var tt = readLine()!!.toInt()
    while (tt-- > 0) {
        val s = readLine()!!
        val t = readLine()!!
        val n = s.length
        var ok = 1
        var ptr = 0
        for (c in t) {
            if (ptr >= n) {
                ok = 0
                break
            }
            if (c == s[ptr]) {
                ptr++
            } else {
                if (ptr + 1 >= n) {
                    ok = 0
                    break
                }
                if (c == '+' && s[ptr] == '-' && s[ptr + 1] == '-') {
                    ptr += 2
                } else {
                    ok = 0
                    break
                }
            }
        }
        if (ptr < n) {
            ok = 0
        }
        println(if (ok == 1) "YES" else "NO")
    }
}