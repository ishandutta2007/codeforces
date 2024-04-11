fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, q) = readLine()!!.split(" ").map { it.toInt() }
        val s = readLine()!!
        for (j in 1..q) {
            val (l, r) = readLine()!!.split(" ").map { it.toInt() - 1 }
            println(if (s.indexOf(s[l]) < l || s.lastIndexOf(s[r]) > r) "yEs" else "nO")
        }
    }
}