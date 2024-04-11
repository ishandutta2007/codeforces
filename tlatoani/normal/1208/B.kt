import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val array = IntArray(n) { jin.nextInt() }
    val lower = mutableSetOf<Int>()
    val upper = mutableSetOf<Int>()
    var l = 0
    var r = n - 1
    while (l < n && !lower.contains(array[l])) {
        lower.add(array[l])
        l++
    }
    var answer = r - l + 1
    while (r >= 0 && !upper.contains(array[r])) {
        while (lower.contains(array[r])) {
            l--
            lower.remove(array[l])
        }
        upper.add(array[r])
        r--
        answer = min(answer, r - l + 1)
    }
    println(answer)
}