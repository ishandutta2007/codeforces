fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val r = line.substring(0, six).toInt()
    val b = line.substring(six + 1).toInt()
    println(if (r == b) "YES" else "NO")
}