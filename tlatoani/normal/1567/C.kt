fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!
        val x = ("0" + String((n.indices step 2).map { n[it] }.toCharArray())).toLong()
        val y = ("0" + String((1 until n.length step 2).map { n[it] }.toCharArray())).toLong()
        println(((x + 1L) * (y + 1L)) - 2L)
    }
}