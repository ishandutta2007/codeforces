fun main() {
    val n = readLine()!!.toInt()
    val xs = readLine()!!.split(" ").map { it.toInt() }
    val present = BooleanArray(1000001)
    for (x in xs) {
        present[x] = true
    }
    val amt = IntArray(1000001)
    for (y in 1..1000000) {
        for (x in y..1000000 step y) {
            if (present[x]) {
                amt[y]++
            }
        }
    }
    val answer = (1..1000000).count { z -> amt[z] > 0 && (2 * z..1000000 step z).all { y -> amt[y] < amt[z] } } - n
    println(answer)
}