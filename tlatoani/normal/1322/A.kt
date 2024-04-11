fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    if (n % 2 == 1) {
        println(-1)
        return
    }
    if (s.count { it == '(' } != n / 2) {
        println(-1)
        return
    }
    var open = 0
    var close = 0
    var answer = 0
    for (chara in s) {
        var involved = open < close
        when (chara) {
            '(' -> open++
            ')' -> close++
        }
        involved = involved or (open < close)
        if (involved) {
            answer++
        }
    }
    println(answer)
}