fun main() {
    readLine()
    val s = "yy" + readLine()!!
    var answer = 0
    for (j in 2 until s.length) {
        if (s.substring(j - 2, j + 1) == "xxx") {
            answer++
        }
    }
    println(answer)
}