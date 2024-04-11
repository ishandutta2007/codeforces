fun main() {
    val n = readLine()!!.toInt()
    val children = Array(n + 1) { mutableListOf<Int>() }
    for (j in 2..n) {
        children[readLine()!!.toInt()].add(j)
    }
    println(if (children.all { cs -> cs.isEmpty() || cs.count { b -> children[b].isEmpty() } >= 3 }) "Yes" else "No")
}