import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val s = readLine()!!
        val freqs = IntArray(25)
        for (letter in s) {
            freqs[letter - 'a']++
        }
        val maximumLetter = min(25, n / k)
        var res = ""
        for (x in maximumLetter downTo 1) {
            val here = (0 until x).map(freqs::get).minOrNull()!! - res.length
            res += ('a' + x).toString().repeat(here)
        }
        if (res.length > k) {
            res = res.substring(0, k)
        }
        while (res.length < k) {
            res += 'a'
        }
        println(res)
    }
}