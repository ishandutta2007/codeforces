import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        jin.readLine()
        val s = jin.readLine()
        for (chara in 'A'..'Z') {
            if (chara in s && !s.substring(s.indexOf(chara), s.lastIndexOf(chara) + 1).all { it == chara }) {
                out.appendln("nO")
                continue@cases
            }
        }
        out.appendln("yEs")
    }
    print(out)
}