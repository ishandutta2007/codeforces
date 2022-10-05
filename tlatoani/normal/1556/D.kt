fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    fun query(type: String, j: Int, k: Int): Int {
        println("$type $j $k")
        return readLine()!!.toInt()
    }
    fun and(j: Int, k: Int) = query("and", j, k)
    fun or(j: Int, k: Int) = query("or", j, k)
    val ands = listOf(and(1, 2), and(2, 3), and(3, 1))
    val ors = listOf(or(1, 2), or(2, 3), or(3, 1))
    val array = Array(n + 1) { 0 }
    for (j in 1..3) {
        val x = j % 3
        val y = (j + 1) % 3
        val z = (j + 2) % 3
        array[j] = (ors[y] and ors[z]) - (ands[x] - (ands[y] and ands[z]))
    }
    for (j in 4..n) {
        val x = and(1, j)
        val y = or(1, j)
        array[j] = x or (y - array[1])
    }
    array.sort()
    println("finish ${array[k]}")
}