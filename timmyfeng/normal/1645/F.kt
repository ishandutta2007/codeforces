fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }.toMutableList()

    a.sort()
    
    if (a[0] > 1) --a[0]

    for (i in 1 until n) {
        if (a[i] - 1 > a[i - 1]) --a[i]
        else if (a[i] <= a[i - 1]) ++a[i]
    }

    println(a.distinct().size)
}