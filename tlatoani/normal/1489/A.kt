fun main() {
    val n = readLine()!!.toInt()
    val ay = readLine()!!.split(" ").map { it.toInt() }
    val answer = mutableListOf<Int>()
    for (j in 0 until n) {
        if (ay.lastIndexOf(ay[j]) == j) {
            answer.add(ay[j])
        }
    }
    println(answer.size)
    println(answer.joinToString(" "))
}