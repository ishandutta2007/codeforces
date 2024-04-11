fun main() {
    val k = readLine()!!.toLong()
    var curr = 1L
    val amts = LongArray(10) { 1L }
    for (j in 0..999) {
        if (curr >= k) {
            break
        }
        curr /= amts[j % 10]
        amts[j % 10]++
        curr *= amts[j % 10]
    }
    for (j in 0..9) {
        print("codeforces"[j].toString().repeat(amts[j].toInt()))
    }
    println()
}