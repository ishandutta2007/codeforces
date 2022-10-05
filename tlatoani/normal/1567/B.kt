fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        val currXOR = (if (a % 2 == 1) (a - 1) else 0) xor (if ((a / 2) % 2 == 1) 1 else 0)
        println(a + when {
            currXOR == b -> 0
            currXOR xor b == a -> 2
            else -> 1
        })
    }
}