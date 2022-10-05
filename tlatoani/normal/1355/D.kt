fun main() {
    val line = readLine()!!.split(" ")
    val n = line[0].toInt()
    val s = line[1].toInt()
    if (s >= 2 * n) {
        println("YES")
        print("2 ".repeat(n - 1))
        println(s - (2 * (n - 1)))
        println(1)
    } else {
        println("NO")
    }
}