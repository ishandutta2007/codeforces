fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val xs = readLine()!!.split(" ").map { it.toInt() }.reversed()
        var last = Int.MAX_VALUE
        var answer = 0
        for (x in xs) {
            if (last == 0) {
                answer = -1
                break
            }
            var x = x
            while (x >= last) {
                answer++
                x /= 2
            }
            last = x
        }
        println(answer)
    }
}