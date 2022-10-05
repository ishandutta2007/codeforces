fun main() {
    val n = readLine()!!.toInt()
    val strings = Array(n) { readLine()!! }
    strings.sortBy { it.length }
    if ((1 until n).all { strings[it].indexOf(strings[it - 1]) != -1 }) {
        println("YES")
        println(strings.joinToString("\n"))
    } else {
        println("NO")
    }
}