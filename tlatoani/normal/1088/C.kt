fun main() {
    val n = readLine()!!.toInt()
    val array = readLine()!!.split(" ").map { it.toInt() }
    var curr = 0
    println(n + 1)
    for (j in n - 1 downTo 0) {
        val delta = (((j - array[j] - curr) % n) + n) % n
        println("1 ${j + 1} $delta")
        curr += delta
    }
    println("2 $n $n")
}