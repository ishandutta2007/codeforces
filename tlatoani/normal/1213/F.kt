import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val k = line[1].toInt()
    val p = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
    val q = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
    val qInv = IntArray(n + 1)
    val pInv = IntArray(n + 1)
    for (j in 1..n) {
        pInv[p[j]] = j
        qInv[q[j]] = j
    }
    val stackP = Stack<Int>()
    val stackQ = Stack<Int>()
    val seenP = BooleanArray(n + 1)
    val seenQ = BooleanArray(n + 1)
    seenP[0] = true
    var j = 1
    val answer = CharArray(n)
    for (letter in 'a' until 'a' + k) {
        if (j > n) {
            println("NO")
            return
        }
        seenP[j] = true
        seenQ[j] = true
        stackP.push(p[j])
        stackQ.push(q[j])
        while (stackP.isNotEmpty() || stackQ.isNotEmpty()) {
            if (stackP.isNotEmpty()) {
                var a = qInv[stackP.pop()]
                while (!seenQ[a]) {
                    seenQ[a] = true
                    stackQ.push(q[a])
                    a--
                }
            } else {
                var a = pInv[stackQ.pop()]
                while (!seenP[a]) {
                    seenP[a] = true
                    stackP.push(p[a])
                    a--
                }
            }
        }
        while (j <= n && seenP[j]) {
            answer[p[j] - 1] = letter
            j++
        }
    }
    while (j <= n) {
        answer[p[j] - 1] = 'z'
        j++
    }
    println("YES")
    println(String(answer))
}