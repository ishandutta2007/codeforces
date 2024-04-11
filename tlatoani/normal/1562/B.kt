import kotlin.math.min

fun main() {
    val isPrime = BooleanArray(1000) { p -> !(2 until p).any { k -> p % k == 0} }
    isPrime[1] = false
    repeat(readLine()!!.toInt()) {
        readLine()
        val n = readLine()!!.map { it - '0' }
        var answer = 1001
        fun test(number: Int) {
            if (!isPrime[number]) {
                answer = min(answer, number)
            }
        }
        for (j in n.indices) {
            test(n[j])
            for (k in j + 1 until n.size) {
                test((10 * n[j]) + n[k])
                for (l in k + 1 until n.size) {
                    test((100 * n[j]) + (10 * n[k]) + n[l])
                }
            }
        }
        println(answer.toString().length)
        println(answer)
    }
}