fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        println((2..n).joinToString(" ") + " 1")
    }
}