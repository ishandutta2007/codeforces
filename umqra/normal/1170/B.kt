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

fun main() {
    val n = Integer.parseInt(readLine())
    readLine()?.let {
        val list = it.split(" ").map(Integer::parseInt)
        var m1: Int? = null
        var m2: Int? = null
        var bad = 0
        for (i in 0 until n) {
            if (m1 != null && m2 != null && list[m1] > list[i] && list[m2] > list[i]) {
                bad++;
            }
            if (m1 == null || list[m1] < list[i]) {
                m2 = m1
                m1 = i
            } else if (m2 == null || list[m2] < list[i]) {
                m2 = i
            }
        }
        println(bad)
    }
}