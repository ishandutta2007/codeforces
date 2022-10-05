import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val amts = jin.readLine().split(" ").map { it.toInt() }
        if (amts.count { it % 2 == 0 } == 2 || (amts.count { it % 2 == 0 } == 1 && 0 in amts && amts[3] != 0)) {
            println("No")
        } else {
            println("Yes")
        }
    }
}