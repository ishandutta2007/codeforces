fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val t = readLine()!!
        if (t == "a") {
            println(1)
        } else if ('a' in t) {
            println(-1)
        } else {
            println(1L shl s.length)
        }
    }
}