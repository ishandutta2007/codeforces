import java.util.*

// A
//import kotlin.math.max
//
//fun main() {
//    val n = Integer.parseInt(readLine())
//    for (i in 1..n) {
//        readLine()?.split(" ")?.map(Integer::parseInt)?.let {
//            val (x, y) = it
//            val a = max(1, 1 + x - y)
//            val b = x - a
//            val c = y - b
//            println("${a} ${b} ${c}")
//        }
//    }
//}

// B
//fun main() {
//    val n = Integer.parseInt(readLine())
//    readLine()?.let {
//        val list = it.split(" ").map(Integer::parseInt)
//        var m1: Int? = null
//        var m2: Int? = null
//        var bad = 0
//        for (i in 0 until n) {
//            if (m1 != null && m2 != null && list[m1] > list[i] && list[m2] > list[i]) {
//                bad++;
//            }
//            if (m1 == null || list[m1] < list[i]) {
//                m2 = m1
//                m1 = i
//            } else if (m2 == null || list[m2] < list[i]) {
//                m2 = i
//            }
//        }
//        println(bad)
//    }
//}

// C
//fun match(source: String, target: String): Boolean {
//    var a = 0
//    var b = 0
//    while (a < source.length && b < target.length) {
//        if (source[a] == target[b]) {
//            a++
//            b++
//        } else if (source[a] == '+') {
//            return false
//        } else {
//            if (a + 1 == source.length || source[a + 1] == '+') {
//                return false
//            }
//            a += 2
//            b++
//        }
//    }
//    return a == source.length && b == target.length
//}
//
//fun main() {
//    val n = Integer.parseInt(readLine())
//    for (i in 0 until n) {
//        val source = readLine()!!
//        val target = readLine()!!
//        println(if (match(source, target)) "YES" else "NO")
//    }
//}

// D
fun main() {
    Integer.parseInt(readLine())

    val decoded = readLine()!!.split(" ").map(Integer::parseInt)
    val count = decoded.count { it == -1 }
    val lists = (0 until count).map { mutableListOf<Int>() }
    val next = ((1..count).toMutableList() + mutableListOf(count + 1)).toMutableList()

    var previous = 0
    for (x in decoded) {
        if (x == -1) {
            next[previous] = next[next[previous]]
        } else {
            previous = next[previous]
            lists[previous - 1].add(x)
        }
        if (next[previous] == count + 1) {
            previous = 0
        }
    }
    println(count)
    for (list in lists) {
        println("${list.size} ${list.joinToString(" ")}")
    }
}