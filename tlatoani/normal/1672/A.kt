fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val logs = readLine()!!.split(" ").map { it.toInt() }
        println(if ((logs.sum() - n) % 2 == 0) "maomao90" else "errorgorn")
    }
}