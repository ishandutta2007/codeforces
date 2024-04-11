fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val redParities = BooleanArray(2)
        val whiteParities = BooleanArray(2)
        for (y in 0 until n) {
            val line = readLine()!!
            for (x in 0 until m) {
                if (line[x] == 'R') {
                    redParities[(y + x) % 2] = true
                } else if (line[x] == 'W') {
                    whiteParities[(y + x) % 2] = true
                }
            }
        }
        if (redParities.all { it } || whiteParities.all { it } || (redParities[0] && whiteParities[0]) || (redParities[1] && whiteParities[1])) {
            println("nO")
        } else {
            var even = if (redParities[0] || whiteParities[1]) 'R' else 'W'
            var odd = if (even == 'R') 'W' else 'R'
            println("yEs")
            repeat(n) { y -> println(CharArray(m) { x -> if ((y + x) % 2 == 0) even else odd }) }
        }
    }
}