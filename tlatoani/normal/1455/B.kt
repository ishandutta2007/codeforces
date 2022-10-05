fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var x = readLine()!!.toInt()
        for (answer in 1..3000) {
            x -= answer
            if (x == 0 || x <= -2) {
                println(answer)
                break
            }
        }
    }
}