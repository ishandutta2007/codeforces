import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val array = jin.readLine().split(" ").map { it.toInt() }
        var alice = 0
        var a = 0
        var bob = 0
        var b = n - 1
        var moves = 0
        var prev = 0
        while (a <= b) {
            moves++
            if (moves % 2 == 0) {
                var curr = 0
                while (curr <= prev && a <= b) {
                    curr += array[b]
                    b--
                }
                bob += curr
                prev = curr
            } else {
                var curr = 0
                while (curr <= prev && a <= b) {
                    curr += array[a]
                    a++
                }
                alice += curr
                prev = curr
            }
        }
        println("$moves $alice $bob")
    }
}