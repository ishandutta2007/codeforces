import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val s = jin.readLine().toCharArray()
    var x = Array(3) { y -> (0 until n).filter { s[it] == '0' + y }.toMutableList() }
    if (x[0].size > n / 3) {
        for (j in n / 3 until x[0].size) {
            if (x[1].size < n / 3) {
                s[x[0][j]] = '1'
                x[1].add(x[0][j])
            } else {
                s[x[0][j]] = '2'
                x[2].add(x[0][j])
            }
        }
    } else {
        for (j in 0 until n) {
            if (x[0].size == n / 3) {
                break
            }
            if (s[j] != '0' && x[s[j] - '0'].size > n / 3) {
                x[s[j] - '0'].removeAt(x[s[j] - '0'].size - 1)
                s[j] = '0'
                x[0].add(j)
            }
        }
    }
    x = Array(3) { y -> (0 until n).filter { s[it] == '0' + y }.toMutableList() }
    if (x[1].size > n / 3) {
        for (j in n / 3 until x[1].size) {
            s[x[1][j]] = '2'
            x[2].add(x[1][j])
        }
    } else {
        for (j in 0 until n) {
            if (x[1].size == n / 3) {
                break
            }
            if (s[j] == '2') {
                s[j] = '1'
                x[1].add(j)
            }
        }
    }
    println(s)
}