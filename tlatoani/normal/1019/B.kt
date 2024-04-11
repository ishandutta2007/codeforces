import kotlin.math.sign

fun main() {
    val n = readLine()!!.toInt()
    fun query(k: Int): Int {
        println("? $k")
        val a = readLine()!!.toInt()
        println("? ${k + (n / 2)}")
        val b = readLine()!!.toInt()
        return a - b
    }
    val init = query(1)
    if (init and 1 == 1) {
        println("! -1")
    } else if (init == 0) {
        println("! 1")
    } else {
        var s = init.sign
        var lower = 1
        var upper = (n / 2) + 1
        while (true) {
            val mid = (lower + upper) / 2
            val d = query(mid)
            if (d == 0) {
                println("! $mid")
                return
            } else if (d.sign == s) {
                lower = mid + 1
            } else {
                upper = mid - 1
            }
        }
    }
}