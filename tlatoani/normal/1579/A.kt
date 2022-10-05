fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        println(if (s.count { it == 'B' } == s.count { it == 'A' || it == 'C' }) "yEs" else "nO")
    }
}