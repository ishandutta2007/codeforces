fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!.split(" ")
        println(line[0].toInt() + line[1].toInt())
    }
}