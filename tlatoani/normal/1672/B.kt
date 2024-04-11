fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        var answer = s.endsWith("B")
        var delta = 0
        for (letter in s) {
            when (letter) {
                'A' -> delta++
                'B' -> delta--
            }
            if (delta < 0) {
                answer = false
            }
        }
        println(if (answer) "yEs" else "nO")
    }
}