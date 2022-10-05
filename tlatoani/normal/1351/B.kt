fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val rect1 = readLine()!!.split(" ").map { it.toInt() }.sorted()
        val rect2 = readLine()!!.split(" ").map { it.toInt() }.sorted()
        if (rect1[0] + rect2[0] == rect1[1] && rect1[1] == rect2[1]) {
            println("yEs")
        } else {
            println("nO")
        }
    }
}