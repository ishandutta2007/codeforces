import java.util.*

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val numbers = IntArray(n + 1)
    val left = TreeSet<Int>(compareBy({ numbers[it] }, { it }))
    val right = TreeSet<Int>(compareBy({ numbers[it] }, { it }))
    left.add(0)
    right.add(0)
    val leftTo = IntArray(n + 1) { -1 }
    val rightTo = IntArray(n + 1) { -1 }
    for (j in 1..n) {
        numbers[j] = readLine()!!.toInt()
        val (l1, r1) = readLine()!!.split(" ").map { it.toInt() }
        val (l2, r2) = readLine()!!.split(" ").map { it.toInt() }
        while (left.isNotEmpty() && numbers[left.first()] < l1) {
            left.remove(left.first())
        }
        while (left.isNotEmpty() && numbers[left.last()] > r1) {
            left.remove(left.last())
        }
        while (right.isNotEmpty() && numbers[right.first()] < l2) {
            right.remove(right.first())
        }
        while (right.isNotEmpty() && numbers[right.last()] > r2) {
            right.remove(right.last())
        }
        if (numbers[j] in l1..r1 && right.isNotEmpty()) {
            leftTo[j] = right.first()
        } else {
            right.clear()
        }
        if (numbers[j] in l2..r2 && left.isNotEmpty()) {
            rightTo[j] = left.first()
        } else {
            left.clear()
        }
        if (leftTo[j] != -1) {
            left.add(j)
        }
        if (rightTo[j] != -1) {
            right.add(j)
        }
    }
    if (left.isEmpty() && right.isEmpty()) {
        println("No")
    } else {
        println("Yes")
        var leftRN: Boolean
        var j: Int
        if (left.isNotEmpty()) {
            leftRN = true
            j = left.first()
        } else {
            leftRN = false
            j = right.first()
        }
        val process = StringJoiner(" ")
        for (k in n downTo 1) {
            if (k == j) {
                process.add(if (leftRN) "0" else "1")
                j = (if (leftRN) leftTo else rightTo)[j]
                leftRN = !leftRN
            } else {
                process.add(if (leftRN) "1" else "0")
            }
        }
        println(process.toString().reversed())
    }
}