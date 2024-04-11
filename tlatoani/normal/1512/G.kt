import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val before = IntArray(10000001)
    val sumOfDivisors = LongArray(10000001)
    sumOfDivisors[1] = 1L
    val answers = IntArray(10000001) { -1 }
    for (p in 2..10000000) {
        if (sumOfDivisors[p] == 0L) {
            for (k in p..10000000 step p) {
                if (sumOfDivisors[k / p] != 0L) {
                    if ((k / p) % p == 0) {
                        before[k] = before[k / p]
                        sumOfDivisors[k] = sumOfDivisors[before[k]] * ((sumOfDivisors[k / p] / sumOfDivisors[before[k]]) + (k / before[k]).toLong())
                    } else {
                        before[k] = k / p
                        sumOfDivisors[k] = sumOfDivisors[before[k]] * (1L + p.toLong())
                    }
                }
            }
        }
    }
    for (k in 10000000 downTo 1) {
        if (sumOfDivisors[k] <= 10000000L) {
            answers[sumOfDivisors[k].toInt()] = k
        }
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        out.appendln(answers[jin.readLine().toInt()])
    }
    print(out)
}