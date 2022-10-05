import kotlin.system.exitProcess

fun main() {
    val n = readLine()!!.toInt()
    var m = 1
    for (j in 1..n) {
        if (n - ((n + j - 1) / j) - (j - 1) > n - ((n + m - 1) / m) - (m - 1)) {
            m = j
        }
    }
    val lamps = BooleanArray(n)
    var amtOn = 0
    fun query(ixs: List<Int>) {
        for (j in ixs) {
            if (!lamps[j]) {
                amtOn++
            }
            lamps[j] = true
        }
        println("${ixs.size} " + ixs.joinToString(" "))
        val x = readLine()!!.toInt()
        if (x == -1) {
            exitProcess(0)
        }
        for (j in x until x + ixs.size) {
            if (lamps[j % n]) {
                amtOn--
            }
            lamps[j % n] = false
        }
    }
    val optimal = n - ((n + m - 1) / m) - (m - 1)
    while (amtOn < optimal) {
        val ixs = mutableListOf<Int>()
        for (j in 0 until n) {
            if (ixs.size == m) {
                break
            }
            if (!lamps[j] && j % m != 0) {
                ixs.add(j)
            }
        }
        query(ixs)
    }
    println(0)
}