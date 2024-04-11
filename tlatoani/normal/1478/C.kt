fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ds = readLine()!!.split(" ").map { it.toLong() }.sorted()
        if ((1 until 2 * n).all { (ds[it - 1] == ds[it]) == (it % 2 == 1) }) {
            var works = true
            var sum = 0L
            var curr = 0L
            for (j in 2 until 2 * n step 2) {
                if ((ds[j] - ds[j - 2]) % j.toLong() == 0L) {
                    curr += (ds[j] - ds[j - 2]) / j.toLong()
                    sum += curr
                } else {
                    works = false
                    break
                }
            }
            sum *= 2L
            println(if (works && ds[0] > sum && (sum - ds[0]) % (2 * n).toLong() == 0L) "yEs" else "nO")
        } else {
            println("nO")
        }
    }
}