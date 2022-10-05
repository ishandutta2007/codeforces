fun main() = repeat(readLine()!!.toInt()) {
    readLine()!!
    println(readLine()!!.split(" ").reversed().joinToString(" "))
}