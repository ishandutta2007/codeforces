import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var exceptionType: String? = null
    var amt = 0
    for (j in 1..jin.readLine().toInt()) {
        var line = jin.readLine().trim()
        if (line.startsWith("try")) {
            if (exceptionType != null) {
                amt++
            }
        } else if (line.startsWith("throw")) {
            line = line.substring(5)
            line = line.trim()
            line = line.substring(1, line.length - 1)
            line = line.trim()
            exceptionType = line
        } else if (line.startsWith("catch")) {
            if (exceptionType != null) {
                if (amt == 0) {
                    line = line.substring(5)
                    line = line.trim()
                    line = line.substring(1, line.length - 1)
                    line = line.trim()
                    val type = line.substringBefore(',').trim()
                    if (type == exceptionType) {
                        line = line.substringAfter(',').trim()
                        line = line.substring(1, line.length - 1)
                        println(line)
                        return
                    }
                } else {
                    amt--
                }
            }
        }
    }
    println("Unhandled Exception")
}