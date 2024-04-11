fun main() {
    val n = readLine()!!.toInt()
    if (n == 1) {
        println("! 1")
        return
    }
    val p = IntArray(n + 1)
    fun query(j: Int) {
        println("? $j")
        p[j] = readLine()!!.toInt()
    }
    query(1)
    query(n)
    var a = 1
    var b = 0
    var c = n
    while (c - a > 1 && (b - a > 1 || c - b > 1)) {
        if (b == 0) {
            val mid = (a + c) / 2
            query(mid)
            if (p[mid] > p[a]) {
                c = mid
            } else if (p[mid] > p[c]) {
                a = mid
            } else {
                b = mid
            }
        } else if (b - a > c - b) {
            val mid = (a + b) / 2
            query(mid)
            if (p[mid] < p[b]) {
                c = b
                b = mid
            } else {
                a = mid
            }
        } else {
            val mid = (b + c) / 2
            query(mid)
            if (p[mid] < p[b]) {
                a = b
                b = mid
            } else {
                c = mid
            }
        }
    }
    if (b == 0) {
        if (p[a] < p[c]) {
            println("! $a")
        } else {
            println("! $c")
        }
    } else {
        println("! $b")
    }
}