fun main() {
    for (c in 1..readLine()!!.toInt()) {
        readLine()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        val by = readLine()!!.split(" ").map { it.toInt() }
        println(ay.toSet().intersect(by).size)
    }
}