fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        val a = line.substring(0, six).toInt()
        val b = line.substring(six + 1).toInt()
        println(when {
            a == b -> 0
            (b > a) == ((a + b) % 2 == 1) -> 1
            else -> 2
        })
    }
}