fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        val t = s.toList().sorted()
        println((0 until n).count { s[it] != t[it] })
    }
}