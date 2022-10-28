fun main() {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map { it.toInt() }

    a = a.sorted()

    var ans = 0
    for (i in 0 until n step 2) {
        ans += a[i + 1] - a[i]
    }

    println(ans)
}