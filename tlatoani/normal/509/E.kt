fun main() {
    val string = readLine()!!.map { if (it in "AEIOUY") 1 else 0 }
    var answer = .0
    var s = 0L
    var t = string.sum()
    for (l in 1..(string.size + 1) / 2) {
        if (l > 1) {
            t -= string[l - 2]
            t -= string[string.size - l + 1]
        }
        s += t
        answer += s.toDouble() / l.toDouble()
        if (2 * l <= string.size) {
            answer += s.toDouble() / (string.size - l + 1).toDouble()
        }
    }
    println(answer)
}