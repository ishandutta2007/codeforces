import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextLine().toInt()
    val lights = jin.nextLine().map { chara -> (chara - '0') }.toMutableList()
    val a = IntArray(n)
    val b = IntArray(n)
    for (i in 0 until n) {
        a[i] = jin.nextInt()
        b[i] = jin.nextInt()
    }
    var answer = lights.sum()
    for (i in 1..240) {
        for (l in 0 until n) {
            if (i >= b[l] && (i - b[l]) % a[l] == 0) {
                lights[l] = 1 - lights[l]
            }
        }
        answer = max(answer, lights.sum())
    }
    println(answer)
}