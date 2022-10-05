import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val out = StringBuilder()
    when {
        n % 2 == 0 && (n == 2 || m > 1) -> {
            out.appendln(0)
            out.appendln("1 1")
            for (y in 1..n) {
                if (y % 2 == 1) {
                    for (x in 2..m) {
                        out.appendln("$y $x")
                    }
                } else {
                    for (x in m downTo 2) {
                        out.appendln("$y $x")
                    }
                }
            }
            for (y in n downTo 1) {
                out.appendln("$y 1")
            }
        }
        m % 2 == 0 && (m == 2 || n > 1) -> {
            out.appendln(0)
            out.appendln("1 1")
            for (x in 1..m) {
                if (x % 2 == 1) {
                    for (y in 2..n) {
                        out.appendln("$y $x")
                    }
                } else {
                    for (y in n downTo 2) {
                        out.appendln("$y $x")
                    }
                }
            }
            for (x in m downTo 1) {
                out.appendln("1 $x")
            }
        }
        else -> {
            out.appendln(1)
            out.appendln("$n $m 1 1")
            for (y in 1..n) {
                if (y % 2 == 1) {
                    for (x in 1..m) {
                        out.appendln("$y $x")
                    }
                } else {
                    for (x in m downTo 1) {
                        out.appendln("$y $x")
                    }
                }
            }
            out.appendln("1 1")
        }
    }
    print(out)
}