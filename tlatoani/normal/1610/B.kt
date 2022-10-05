fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        val reversed = ay.reversed()
        if (ay == reversed) {
            println("yEs")
        } else {
            val j = (0 until n).first { ay[it] != reversed[it] }
            if (ay.filter { it != ay[j] }.let { it == it.reversed() } || ay.filter { it != reversed[j] }.let { it == it.reversed() }) {
                println("Yes")
            } else {
                println("nO")
            }
        }
    }
}