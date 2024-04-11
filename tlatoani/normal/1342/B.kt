fun main() {
    repeat(readLine()!!.toInt()) {
        val t = readLine()!!
        if (t.all { it == '0' } || t.all { it == '1' }) {
            println(t)
        } else {
            println("01".repeat(t.length))
        }
    }
}