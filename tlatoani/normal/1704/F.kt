val initial = listOf(0, 0, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 0, 5, 2, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 2, 7, 4, 0, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 2, 3, 3)
val periodic = listOf(0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4, 8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9, 3, 3)

fun main() {
    val nimbers = initial + List(500001) { periodic[it % periodic.size] }
    repeat(readLine()!!.toInt()) {
        readLine()
        val s = readLine()!!
        var last = 'X'
        var curr = 0
        var totalNimber = 0
        var diff = 0
        for (chara in s) {
            if (chara == last) {
                totalNimber = totalNimber xor nimbers[curr]
                curr = 0
            }
            curr++
            last = chara
            when (chara) {
                'R' -> diff++
                'B' -> diff--
            }
        }
        totalNimber = totalNimber xor nimbers[curr]
        println(when {
            diff > 0 -> "Alice"
            diff < 0 -> "Bob"
            totalNimber == 0 -> "Bob"
            else -> "Alice"
        })
    }
}