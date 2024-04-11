fun main() {
    val t = readLine()!!.toInt()

    for (tt in 1..t) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }

        val b = a.sorted()

        println(a.indexOf(b[0] xor b[1] xor b[n - 1]) + 1)
    }
}