fun main() = repeat(readLine()!!.toInt()) {
    val dims = readLine()!!.split(" ").map { it.toInt() }
    println(((dims[0] * dims[1]) + 1) / 2)
}