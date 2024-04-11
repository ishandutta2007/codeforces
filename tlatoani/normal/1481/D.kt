import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val edges = arrayOf("") + Array(n) { " " + jin.readLine() }
        if (m % 2 == 1) {
            out.appendln("YES")
            for (j in 0..m) {
                out.append((j % 2) + 1).append(' ')
            }
            out.appendln()
        } else {
            var answer = false
            upLoop@for (u in 1..n) {
                for (v in 1..n) {
                    if (v != u && edges[u][v] == edges[v][u]) {
                        answer = true
                        out.appendln("YES")
                        for (j in 0..m) {
                            out.append(if (j % 2 == 0) u else v).append(' ')
                        }
                        out.appendln()
                        break@upLoop
                    }
                }
            }
            if (!answer) {
                for (r in 1..n) {
                    var inA = 0
                    var inB = 0
                    var outA = 0
                    var outB = 0
                    for (v in 1..n) {
                        if (edges[v][r] == 'a') {
                            inA = v
                        } else if (edges[v][r] == 'b') {
                            inB = v
                        }
                        if (edges[r][v] == 'a') {
                            outA = v
                        } else if (edges[r][v] == 'b') {
                            outB = v
                        }
                    }
                    if (inA != 0 && outA != 0) {
                        answer = true
                        out.appendln("YES")
                        for (j in 0..m) {
                            out.append(when {
                                j % 2 == (m / 2) % 2 -> r
                                j < m / 2 -> inA
                                else -> outA
                            }).append(' ')
                        }
                        out.appendln()
                        break
                    }
                    if (inB != 0 && outB != 0) {
                        answer = true
                        out.appendln("YES")
                        for (j in 0..m) {
                            out.append(when {
                                j % 2 == (m / 2) % 2 -> r
                                j < m / 2 -> inB
                                else -> outB
                            }).append(' ')
                        }
                        out.appendln()
                        break
                    }
                }
            }
            if (!answer) {
                out.appendln("NO")
            }
        }
    }
    print(out)
}