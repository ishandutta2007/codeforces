fun main() {
    val n = readLine()!!.toInt()
    fun query(from: Int, to: Int): Int {
        return if (from == to) {
            0
        } else {
            println("? $from $to")
            readLine()!!.toInt()
        }
    }
    val k = query(1, n)
    if (query(1, k) == k) {
        var upper = k
        var lower = 1
        while (upper > lower) {
            val mid = (upper + lower + 1) / 2
            if (query(mid, k) == k) {
                lower = mid
            } else {
                upper = mid - 1
            }
        }
        println("! $lower")
    } else {
        var upper = n
        var lower = k
        while (upper > lower) {
            val mid = (upper + lower) / 2
            if (query(k, mid) == k) {
                upper = mid
            } else {
                lower = mid + 1
            }
        }
        println("! $upper")
    }
}