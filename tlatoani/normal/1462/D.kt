fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        val s = ay.sum()
        kLoop@for (k in n downTo 1) {
            if (s % k == 0) {
                var curr = 0
                for (a in ay) {
                    curr += a
                    if (curr > s / k) {
                        continue@kLoop
                    } else if (curr == s / k) {
                        curr = 0
                    }
                }
                if (curr == 0) {
                    println(n - k)
                    break
                }
            }
        }
    }
}