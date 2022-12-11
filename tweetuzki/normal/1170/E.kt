import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val n = nextInt()
    val m = nextInt()
    var a = Array(n + 5, {0})
    for (i in 1 .. n) a[i] = nextInt()
    var pre = Array(n + 5, {0})
    for (i in 1 .. n) pre[i] = pre[i - 1] + a[i]
    val q = nextInt()
    repeat(q) {
        val k = nextInt()
        val b = Array(k + 5, {0})
        for (i in 1 .. k) b[i] = nextInt()
        b[0] = 0
        b[k + 1] = m + 1
        var j = 1
        for (i in 1 .. k + 1) {
            var d = b[i] - b[i - 1] - 1
            var lbound = j
            var rbound = n
            var ans = j - 1
            while (lbound <= rbound) {
                val mid = (lbound + rbound) / 2
                if (pre[mid] - pre[j - 1] <= d) {
                    ans = mid
                    lbound = mid + 1
                } else {
                    rbound = mid - 1
                }
            }
            j = ans + 1
        }
        if (j == n + 1) println("YES")
        else println("NO")
    }
}