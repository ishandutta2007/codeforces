import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        jin.readLine()
        println(jin.readLine().split(" ").count { it != "2" })
    }
}