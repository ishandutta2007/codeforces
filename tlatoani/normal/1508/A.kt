import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val prompts = Array(3) { jin.readLine() }
        for (b in '0'..'1') {
            for (x in 0..2) {
                for (y in x + 1..2) {
                    if (prompts[x].count { it == b } >= n && prompts[y].count { it == b } >= n) {
                        var j = 0
                        var k = 0
                        for (d in 1..n) {
                            while (prompts[x][j] != b) {
                                out.append(prompts[x][j])
                                j++
                            }
                            while (prompts[y][k] != b) {
                                out.append(prompts[y][k])
                                k++
                            }
                            out.append(b)
                            j++
                            k++
                        }
                        while (j < 2 * n) {
                            out.append(prompts[x][j])
                            j++
                        }
                        while (k < 2 * n) {
                            out.append(prompts[y][k])
                            k++
                        }
                        out.appendln()
                        continue@cases
                    }
                }
            }
        }
    }
    print(out)
}