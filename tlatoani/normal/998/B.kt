import kotlin.math.abs

fun main() {
    val (n, b) = readLine()!!.split(" ").map { it.toInt() }
    val a = readLine()!!.split(" ").map { it.toInt() }
    val cuts = mutableListOf<Int>()
    var odd = 0
    var even = 0
    if (a[0] % 2 == 0) {
        even++
    } else {
        odd++
    }
    for (j in 1 until n) {
        if (even == odd) {
            cuts.add(abs(a[j] - a[j - 1]))
        }
        if (a[j] % 2 == 0) {
            even++
        } else {
            odd++
        }
    }
    cuts.sort()
    var answer = 0
    var sum = 0
    for (c in cuts) {
        if (sum + c <= b) {
            answer++
            sum += c
        } else {
            break
        }
    }
    println(answer)
}