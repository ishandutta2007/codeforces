fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    var answer = 0
    for (j in 2 until n) {
        if (s[j] == 'x' && s[j - 1] == 'x' && s[j - 2] == 'x') {
            answer++
        }
    }
    println(answer)
}