import java.util.*
import kotlin.math.max

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    if (n == 1 && k == 0) {
        println("YES")
        println("0")
        return
    }
    if (n % 2 == 0 || k > (n - 3) / 2) {
        println("NO")
        return
    }
    var e = 0
    while (n - max(0, 2 * (k - 1)) >= (1 shl e) - 1) {
        e++
    }
    e--
    if (k == 0 && n != (1 shl e) - 1) {
        println("NO")
        return
    }
    if (k == 1 && n == (1 shl e) - 1) {
        println("NO")
        return
    }
    if (n == 9 && k == 2) {
        println("NO")
        return
    }
    val special = k > 1 && n - (2 * (k - 1)) == (1 shl e) - 1
    val answer = IntArray(n + 1)
    var a = 1
    val q = LinkedList<Int>()
    q.add(a)
    while (n - a > max(0, if (special) (2 * k) else (2 * (k - 1)))) {
        a++
        answer[a] = q[0]
        q.add(a)
        a++
        answer[a] = q.remove()
        q.add(a)
    }
    var b = 1
    for (j in 1 until k) {
        answer[b] = a + 2
        answer[a + 1] = a + 2
        a += 2
        b = a
    }
    if (special) {
        answer[a + 1] = a - 1
        answer[a + 2] = a - 1
    }
    println("YES")
    println(answer.joinToString(" ").substring(2))
}