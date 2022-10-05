fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        if (xs.all { it == 0 }) {
            println(0)
        } else {
            val from = xs.indexOfFirst { it != 0 }
            val to = xs.indexOfLast { it != 0 }
            if (xs.subList(from, to + 1).all { it != 0 }) {
                println(1)
            } else {
                println(2)
            }
        }
    }
}