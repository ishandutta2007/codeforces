import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val sums = IntArray(n + 1) {i -> if (i == 0) 0 else jin.nextInt() }
    for (i in 1..n) {
        sums[i] += sums[i - 1]
    }
    val q = jin.nextInt()
    val answers = StringJoiner("\n")
    for (i in 1..q) {
        val l = jin.nextInt()
        val r = jin.nextInt()
        answers.add("" + (sums[r] - sums[l - 1]) / 10)
    }
    println(answers)
}