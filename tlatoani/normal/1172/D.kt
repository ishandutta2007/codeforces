import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    var tokenizer = StringTokenizer(readLine()!!)
    val goal1 = intArrayOf(0) + IntArray(n) { tokenizer.nextToken().toInt() }
    tokenizer = StringTokenizer(readLine()!!)
    val goal2 = intArrayOf(0) + IntArray(n) { tokenizer.nextToken().toInt() }
    val goal1Inv = IntArray(n + 1)
    val goal2Inv = IntArray(n + 1)
    for (j in 1..n) {
        goal1Inv[goal1[j]] = j
        goal2Inv[goal2[j]] = j
    }
    val p1 = IntArray(n + 1) { it }
    val q1 = IntArray(n + 1) { it }
    val p2 = IntArray(n + 1) { it }
    val q2 = IntArray(n + 1) { it }
    val doors = mutableListOf<Door>()
    for (j in 1..n) {
        doors.add(Door(j, p2[goal2Inv[j]], p1[goal1Inv[j]], j))

        var a = goal1Inv[j]
        var b = p1[a]
        var c = q1[j]
        p1[a] = j
        q1[j] = a
        p1[c] = b
        q1[b] = c

        a = goal2Inv[j]
        b = p2[a]
        c = q2[j]
        p2[a] = j
        q2[j] = a
        p2[c] = b
        q2[b] = c
    }
    doors.removeAll { it.x1 == it.x2 && it.y1 == it.y2 }
    println(doors.size)
    for (door in doors) {
        println("${door.x1} ${door.y1} ${door.x2} ${door.y2}")
    }
}

data class Door(val x1: Int, val y1: Int, val x2: Int, val y2: Int)