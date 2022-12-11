import java.util.*
fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var te = nextInt()
    nextLine()
    repeat(te) {
        val s = nextLine()
        val t = nextLine()
        val n = s.length
        val m = t.length
        var ok = true
        var i = 0
        for (j in 0 until m) {
            if (i == n) {
                ok = false
                break
            }
            if (t[j] == '-') {
                if (s[i] == '-') i++
                else ok = false
            } else {
                if (s[i] == '+') i++
                else {
                    if (i + 1 == n || s[i + 1] == '+') ok = false
                    else i += 2
                }
            }
            if (ok == false) break
        }
        if (i != n) ok = false
        if (ok == false) {
            println("NO")
        } else {
            println("YES")
        }
    }
}