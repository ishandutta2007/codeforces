fun main() {
    val n = readLine()!!.toInt()
    fun query(a: Int, b: Int): Int {
        println("? $a $b")
        return readLine()!!.toInt()
    }
    val p = IntArray(n) { query(it, 0) }
    val b = IntArray(n) { query(0, it) xor p[0] }
    var amt = 0
    var validB0 = -1
    for (b0 in 0 until n) {
        if (p.all { it xor b0 < n } && b.all { it xor b0 < n } && (0 until n).all { p[b[it] xor b0] xor b0 == it }) {
            amt++
            validB0 = b0
        }
    }
    println("!")
    println(amt)
    println(p.map { it xor validB0 }.joinToString(" "))
}