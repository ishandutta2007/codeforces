fun main() {
    println(readLine()!!.toInt().toString(2).count { it == '1' })
}