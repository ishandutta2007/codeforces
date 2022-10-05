fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!.split(" ")
        val k = line[0].toInt()
        val n = line[1].toInt()
        println((k * ((n - 1) / (k - 1))) + ((n - 1) % (k - 1)) + 1)
    }
}