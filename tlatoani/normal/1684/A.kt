fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!
        if (n.length == 2) {
            println(n.last())
        } else {
            println(n.min()!!)
        }
    }
}