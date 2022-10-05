fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!.toInt()
        for (answer in 1..s) {
            if (s in answer..answer * answer) {
                println(answer)
                break
            }
        }
    }
}