fun main() {
    for (c in 1..readLine()!!.toInt()) {
        readLine()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        val xum = xs.reduce { x, y -> x xor y }
        if (xum == 0) {
            println("YES")
        } else {
            var curr = 0
            var times = 0
            for (x in xs) {
                curr = curr xor x
                if (curr == xum) {
                    times++
                    curr = 0
                }
            }
            println(if (times > 1) "YES" else "NO")
        }
    }
}