fun main() {
    repeat(readLine()!!.toInt()) {
        val (l, r) = readLine()!!.split(' ').map { it.toInt() }
        println(if (2 * l > r) "YES" else "NO");
    }
}