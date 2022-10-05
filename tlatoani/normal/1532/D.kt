fun main() {
    val n = readLine()!!.toInt()
    val skills = readLine()!!.split(" ").map { it.toInt() }.sorted()
    println((0 until n step 2).map { skills[it + 1] - skills[it] }.sum())
}