fun main() {
    val x = readLine()!!.toInt()
    if (x == 1) {
        println(-1)
    } else {
        println("${x - (x and 1)} 2")
    }
}