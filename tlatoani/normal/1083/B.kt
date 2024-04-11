import kotlin.math.min

fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val k = line.substring(six + 1).toLong()
    val s = readLine()!!
    val t = readLine()!!
    if (s == t || k == 1L) {
        println(n)
        return
    }
    var same = 0
    while (s[same] == t[same]) {
        same++
    }
    var answer = same.toLong()
    var j = same + 1
    answer += 2L
    var curr = 0L
    while (j < n) {
        answer += 2L
        curr *= 2L
        if (curr < k && s[j] == 'a') {
            curr++
        }
        if (curr < k && t[j] == 'b') {
            curr++
        }
        curr = min(curr, k - 2L)
        //println("j = $j, curr = $curr")
        answer += curr
        j++
    }
    println(answer)
}