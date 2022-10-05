import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val pow10 = IntArray(9)
    pow10[0] = 1
    for (j in 1..8) {
        pow10[j] = 10 * pow10[j - 1]
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val out = StringBuilder()
    var prev = -1
    for (bing in 1..n) {
        val number = jin.readLine()
        var curr = number.replace('?', '0').toInt()
        val rev = number.reversed()
        for (j in rev.length - 1 downTo 0) {
            if (rev[j] == '?') {
                var temp = curr
                for (k in j - 1 downTo 0) {
                    if (rev[k] == '?') {
                        temp += 9 * pow10[k]
                    }
                }
                var d = 0
                if (j == rev.length - 1) {
                    d++
                    temp += pow10[j]
                    curr += pow10[j]
                }
                while (temp <= prev && d <= 9) {
                    d++
                    temp += pow10[j]
                    curr += pow10[j]
                }
                if (d == 10) {
                    println("NO")
                    return
                }
            }
        }
        if (curr <= prev) {
            println("NO")
            return
        }
        out.appendln(curr)
        prev = curr
    }
    println("YES")
    print(out)
}