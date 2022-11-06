import java.util.*

fun main() {
    var t = readLine()!!.toInt()
    while (t-- > 0) {
        val (n, k, x, y) = readLine()!!.split(" ").map{ it.toInt() }
        val a = readLine()!!.split(" ").map{ it.toInt() }.sorted().reversed()
        var sum: Long = 0
        for (x in a) sum += x
        var cnt = 0
        for (x in a) {
            if (x > k) cnt += 1
        }
        if (cnt == 0) {
            println("0")
            continue
        }
        var res: Long = 1000000000000000000
        if (sum <= n.toLong() * k) {
            if (y < res) res = y.toLong();
        }
        var cost: Long = 0

        for (b in a) {
            sum -= b
            cost += x
            if (b > k) cnt -= 1
            if (cnt == 0) {
                if (cost < res) res = cost
            }
            if (sum <= n.toLong() * k) {
                if (cost + y < res) res = cost + y
            }
        }
        println(res)
    }
}