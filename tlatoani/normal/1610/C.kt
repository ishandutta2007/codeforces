fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val friends = Array(n) { readLine()!!.split(" ").map { it.toInt() } }
        var upper = n
        var lower = 0
        while (upper > lower) {
            val mid = (upper + lower + 1) / 2
            var rem = mid
            for ((a, b) in friends) {
                if (mid - rem <= b && a >= rem - 1) {
                    rem--
                }
            }
            if (rem <= 0) {
                lower = mid
            } else {
                upper = mid - 1
            }
        }
        println(upper)
    }
}