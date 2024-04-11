fun main() {
    var base = 0
    fun query(exponent: Int): Int {
        val power = 1 shl exponent
        println("? ${200 * (200 / power)}")
        println((1..200).map { x -> (power..200 step power).map { y -> "$x $y" } }.flatten().joinToString(" "))
        val amt = readLine()!!.toInt()
        base = gcd(base, amt)
        return amt
    }
    val area = query(0)
    fun isDivisible(exponent: Int) = area == (1 shl exponent) * query(exponent)
    if (isDivisible(4)) {
        if (isDivisible(6)) {
            if (isDivisible(7)) {
                base = area / 128
            }
        } else {
            query(5)
        }
    } else {
        if (isDivisible(2)) {
            query(3)
        } else {
            query(1)
        }
    }
    val height = area / base
    val perimeter = 2 * ((base - 1) + (height - 1))
    println("! $perimeter")
}

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)