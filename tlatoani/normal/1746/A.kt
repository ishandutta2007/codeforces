fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()!!
        val xs = readLine()!!.split(" ").map { it.toInt() }
        println(if (1 in xs) "YES" else "NO")
    }
}