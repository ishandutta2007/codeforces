import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val doorSums = IntArray(n + 1) { jin.nextInt() }
    val m = doorSums[0]
    doorSums[0] = 0
    for (i in 1..n) {
        doorSums[i] += doorSums[i - 1]
    }
    val answer = StringJoiner("\n")
    for (c in 1..jin.nextInt()) {
        var lastDoor = 0
        var prev = 0
        for (d in 1..jin.nextInt()) {
            val curr = jin.nextInt()
            var lower = lastDoor
            var upper = n
            while (lower < upper) {
                val mid = (lower + upper + 1) / 2
                if (doorSums[mid] - doorSums[lastDoor] <= curr - prev - 1) {
                    lower = mid
                } else {
                    upper = mid - 1
                }
            }
            lastDoor = upper
            prev = curr
        }
        answer.add(if (doorSums[n] - doorSums[lastDoor] <= m - prev) "YES" else "NO")
    }
    println(answer)
}