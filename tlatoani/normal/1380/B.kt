import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        var rock = 0
        var paper = 0
        var scissors = 0
        val s = jin.readLine()
        for (choice in s) {
            when (choice) {
                'R' -> rock++
                'P' -> paper++
                'S' -> scissors++
            }
        }
        val m = maxOf(rock, paper, scissors)
        println(when {
            rock == m -> "P"
            paper == m -> "S"
            else -> "R"
        }.repeat(s.length))
    }
}