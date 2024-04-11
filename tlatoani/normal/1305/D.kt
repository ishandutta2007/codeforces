import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    for (j in 2..n) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        val a = line.substring(0, six).toInt()
        val b = line.substring(six + 1).toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val possible = TreeSet<Int>()
    possible.addAll(1..n)
    val check = TreeSet<Int>()
    for (j in 1..n) {
        if (adj[j].size >= 2) {
            check.add(j)
        }
    }
    while (check.size > 1) {
        val j = check.first()
        var k = 0
        for (kp in adj[j]) {
            if (adj[kp].size >= 2) {
                k = kp
                break
            }
        }
        println("? $j $k")
        val w = readLine()!!.toInt()
        val loser = j + k - w
        adj[w].remove(loser)
        adj[loser].remove(w)
        if (adj[w].size == 1) {
            check.remove(w)
        }
        val stack = Stack<Int>()
        stack.push(loser)
        while (!stack.isEmpty()) {
            val a = stack.pop()
            possible.remove(a)
            check.remove(a)
            for (b in adj[a]) {
                if (possible.contains(b)) {
                    stack.push(b)
                }
            }
        }
    }
    if (possible.size == 1) {
        val r = possible.first()
        println("! $r")
    } else if (possible.size == 2) {
        val a = possible.first()
        val b = possible.last()
        println("? $a $b")
        val w = readLine()!!.toInt()
        println("! $w")
    } else {
        val q = check.first()
        possible.remove(q)
        while (possible.size > 1) {
            val a = possible.first()
            possible.remove(a)
            val b = possible.last()
            possible.remove(b)
            println("? $a $b")
            val w = readLine()!!.toInt()
            if (w == a || w == b) {
                println("! $w")
                return
            }
        }
        if (possible.isEmpty()) {
            println("! $q")
        } else {
            val s = possible.first()
            println("? $q $s")
            val w = readLine()!!.toInt()
            println("! $w")
        }
    }
}