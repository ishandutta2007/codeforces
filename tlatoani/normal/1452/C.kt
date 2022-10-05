import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        var amt1 = 0
        var amt2 = 0
        var answer = 0
        for (chara in jin.readLine()) {
            when (chara) {
                '(' -> amt1++
                ')' -> {
                    if (amt1 > 0) {
                        amt1--
                        answer++
                    } else {
                        amt1 = 0
                    }
                }
                '[' -> amt2++
                ']' -> {
                    if (amt2 > 0) {
                        amt2--
                        answer++
                    } else {
                        amt2 = 0
                    }
                }
            }
        }
        println(answer)
    }
}