fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!
        val answer = mutableListOf<String>()
        for (j in 0 until n.length) {
            if (n[n.length - j - 1] != '0') {
                answer.add(n[n.length - j - 1] + "0".repeat(j))
            }
        }
        println(answer.size)
        println(answer.joinToString(" "))
    }
}