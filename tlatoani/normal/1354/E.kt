import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val m = line[1].toInt()
    line = jin.readLine().split(" ")
    var n1 = line[0].toInt()
    val n2 = line[1].toInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 1..m) {
        val line = jin.readLine().split(" ")
        val a = line[0].toInt()
        val b = line[1].toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val componentsLeft = Array(n + 1) { mutableListOf<Int>() }
    val componentsRight = Array(n + 1) { mutableListOf<Int>() }
    val parity = IntArray(n + 1)
    val stack = Stack<Int>()
    var dp = Array(n + 1) { IntArray(n2 + 1) }
    dp[0][0] = -7000
    var k = 0
    for (r in 1..n) {
        if (parity[r] == 0) {
            k++
            parity[r] = 1
            stack.push(r)
            while (stack.isNotEmpty()) {
                val a = stack.pop()
                if (parity[a] == 1) {
                    componentsLeft[k].add(a)
                } else {
                    componentsRight[k].add(a)
                }
                for (b in adj[a]) {
                    if (parity[b] == 0) {
                        parity[b] = -parity[a]
                        stack.push(b)
                    } else if (parity[b] == parity[a]) {
                        println("NO")
                        return
                    }
                }
            }
            for (j in 0..n2) {
                if (j >= componentsLeft[k].size && dp[k - 1][j - componentsLeft[k].size] != 0) {
                    dp[k][j] = 1
                } else if (j >= componentsRight[k].size && dp[k - 1][j - componentsRight[k].size] != 0) {
                    dp[k][j] = -1
                }
            }
            //println("r = $r")
            //println(componentsLeft[k])
            //println(componentsRight[k])
            //println(dp[k].contentToString())
        }
    }
    if (dp[k][n2] == 0) {
        println("NO")
        return
    }
    val answer = CharArray(n + 1) { '3' }
    var j = n2
    while (k > 0) {
        if (dp[k][j] == 1) {
            j -= componentsLeft[k].size
            for (a in componentsLeft[k]) {
                answer[a] = '2'
            }
        } else {
            j -= componentsRight[k].size
            for (a in componentsRight[k]) {
                answer[a] = '2'
            }
        }
        k--
    }
    for (a in 1..n) {
        if (n1 > 0 && answer[a] == '3') {
            answer[a] = '1'
            n1--
        }
    }
    println("YES")
    println(String(answer).substring(1))
}