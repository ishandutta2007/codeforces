import java.math.BigInteger

val ONE: BigInteger = BigInteger.ONE
val TWO = ONE + ONE
val THREE = ONE + TWO
val FOUR = TWO * TWO

fun main() {
    val out = StringBuilder()
    caseLoop@for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!.split(" ")
        val n = line[0].toInt()
        val k = BigInteger(line[1])
        if (n > 36) {
            out.appendln("YES ${n - 1}")
            continue@caseLoop
        }
        for (alpha in 1..n) {
            val below = TWO.pow(alpha + 1) - TWO - BigInteger.valueOf(alpha.toLong())
            val above = ((FOUR.pow(n) - ONE) / THREE) - ((TWO.pow(alpha + 1) - ONE) * ((FOUR.pow(n - alpha) - ONE) / THREE))
            if (k in below..above) {
                out.appendln("YES ${n - alpha}")
                continue@caseLoop
            }
        }
        out.appendln("NO")
    }
    print(out)
}