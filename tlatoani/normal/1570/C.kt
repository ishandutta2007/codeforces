fun main() {
    val n = readLine()!!.toInt()
    val ay = readLine()!!.split(" ").map { it.toInt() }
    val by = ay.sortedDescending()
    var answer = 0
    for (j in 0 until n) {
        answer += (j * by[j]) + 1
    }
    println(answer)
    println((1..n).sortedBy { -ay[it - 1] }.joinToString(" "))
}