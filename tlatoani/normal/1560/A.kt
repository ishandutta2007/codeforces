fun main() {
    val liked = mutableListOf<Int>()
    for (k in 1..5000) {
        if (liked.size == 1000) {
            break
        }
        if (k % 3 != 0 && k % 10 != 3) {
            liked.add(k)
        }
    }
    repeat(readLine()!!.toInt()) {
        println(liked[readLine()!!.toInt() - 1])
    }
}