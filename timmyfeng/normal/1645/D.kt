fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }

    val count = a.groupingBy { it }.eachCount()
    val inc = mutableListOf<Int>()
    val dec = mutableListOf<Int>()

    for ((x, c) in count) {
        if (c > 2) {
            println("NO")
            return
        } else if (c == 2) {
            inc.add(x)
            dec.add(x)
        } else inc.add(x)
    }

    inc.sort()
    dec.sortDescending()

    println("YES")
    println(inc.size)
    println(inc.joinToString(" "))
    println(dec.size)
    println(dec.joinToString(" "))
}