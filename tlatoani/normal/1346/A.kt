fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!.split(" ").map { it.toInt() }
        val n = line[0]
        val k = line[1]
        val ns = IntArray(4)
        ns[0] = n / (1 + k + (k * k) + (k * k * k))
        for (j in 1..3) {
            ns[j] = ns[j - 1] * k
        }
        println(ns.joinToString(" "))
    }
}