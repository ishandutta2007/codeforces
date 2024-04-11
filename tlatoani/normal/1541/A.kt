fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val answer = mutableListOf<Int>()
        for (k in 2..n - 2 step 2) {
            answer.add(k)
            answer.add(k - 1)
        }
        if (n % 2 == 0) {
            answer.add(n)
            answer.add(n - 1)
        } else {
            answer.add(n)
            answer.add(n - 2)
            answer.add(n - 1)
        }
        println(answer.joinToString(" "))
    }
}