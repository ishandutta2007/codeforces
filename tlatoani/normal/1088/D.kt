fun main() {
    var without = -2
    var with = -2
    var a = 0
    var b = 0
    var bit = 1 shl 29
    fun query(c: Int, d: Int): Int {
        println("? $c $d")
        return readLine()!!.toInt()
    }
    while (bit > 0) {
        if (without == -2) {
            without = query(a, b)
        }
        with = query(a xor bit, b xor bit)
        if (without == with) {
            if (query(a xor bit, b) == -1) {
                a = a xor bit
                b = b xor bit
            }
        } else {
            if (without == -1) {
                b = b xor bit
            } else {
                a = a xor bit
            }
            without = -2
        }
        bit /= 2
    }
    println("! $a $b")
}