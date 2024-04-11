import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        jin.readLine()
        val s1 = jin.readLine()
        val s2 = jin.readLine()
        println(if (normalize(s1) == normalize(s2)) "yEs" else "nO")
    }
}

fun normalize(s: String): List<Int> {
    val res = s.map { it - '0' }.toIntArray()
    var from = 0
    var prefix = 0
    for ((j, chara) in s.withIndex()) {
        when (chara) {
            '0' -> prefix--
            '1' -> prefix++
        }
        if (prefix == 0) {
            if (s[from] == '1') {
                for (k in from..j) {
                    res[k] = 1 - res[k]
                }
            }
            from = j + 1
        }
    }
    return res.toList()
}