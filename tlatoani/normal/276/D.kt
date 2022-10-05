fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val l = line.substring(0, six).toLong()
    val r = line.substring(six + 1).toLong()
    for (e in 60 downTo 0) {
        val b = 1L shl e
        if ((l and b) != (r and b)) {
            println((2L * b) - 1L)
            return
        }
    }
    println(0L)
}