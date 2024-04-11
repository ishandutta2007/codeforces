fun main() {
    repeat(readLine()!!.toInt()) {
        val k = readLine()!!.toInt()
        val g = (1..100).last { k % it == 0 && 100 % it == 0 }
        println(100 / g)
    }
}