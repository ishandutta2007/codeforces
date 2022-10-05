import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val highest = IntArray(51)
    var tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..n) {
        val k = tokenizer.nextToken().toInt()
        if (highest[k] == 0) {
            highest[k] = j
        }
    }
    val joiner = StringJoiner(" ")
    tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..q) {
        val k = tokenizer.nextToken().toInt()
        joiner.add(highest[k].toString())
        for (x in 1..50) {
            if (highest[x] < highest[k]) {
                highest[x]++
            }
        }
        highest[k] = 1
    }
    print(joiner)
}