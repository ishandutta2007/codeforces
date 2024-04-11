import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    var n = jin.nextInt()
    val m = jin.nextInt()
    jin.nextLine()
    val dpl = IntArray(2)
    val dpr = IntArray(2)
    dpl[1] = -1
    dpr[1] = m
    val strings = Array(n) { jin.nextLine() }.toMutableList()
    while (n > 0 && '1' !in strings[0]) {
        strings.removeAt(0)
        n--
    }
    if (n == 0) {
        println(0)
        return
    }
    for (y in 0..n - 2) {
        val b = y % 2
        val s = strings[n - 1 - y]
        val lowest = if ('1' in s) s.indexOf('1') else m + 1
        val highest = if ('1' in s) s.lastIndexOf('1') else 0
        //println("y = $y, lowest = $lowest, highest = $highest")
        dpl[b] = 1 + min(dpl[1 - b] + (2 * highest), dpr[1 - b] + m + 1)
        dpr[b] = 1 + min(dpl[1 - b] + m + 1, dpr[1 - b] + (2 * (m + 1 - lowest)))
        //println("y = $y, l = ${dpl[b]}, r = ${dpr[b]}")
    }
    val b = (n - 1) % 2
    val s = strings[0]
    val lowest = if ('1' in s) s.indexOf('1') else m + 1
    val highest = if ('1' in s) s.lastIndexOf('1') else 0
    val answer = 1 + min(dpl[1 - b] + highest, dpr[1 - b] + (m + 1 - lowest))
    println(answer)
}