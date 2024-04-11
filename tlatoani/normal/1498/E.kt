fun main() {
    val n = readLine()!!.toInt()
    val inc = listOf(0) + readLine()!!.trim().split(" ").map { it.trim().toInt() }
    val pairs = mutableListOf<Pair<Int, Int>>()
    for (a in 1..n) {
        for (b in 1..n) {
            if (inc[a] < inc[b] || (inc[a] == inc[b] && a < b)) {
                pairs.add(Pair(a, b))
            }
        }
    }
    pairs.sortBy { (a, b) -> inc[a] - inc[b] }
    for ((a, b) in pairs) {
        println("? $b $a")
        if (readLine()!! == "Yes") {
            println("! $a $b")
            return
        }
    }
    println("! 0 0")
}