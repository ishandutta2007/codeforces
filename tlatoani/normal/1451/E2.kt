import java.lang.IllegalStateException

fun main() {
    val n = readLine()!!.toInt()
    fun query(type: String, a: Int, b: Int): Int {
        println("$type ${a + 1} ${b + 1}")
        return readLine()!!.toInt()
    }
    val xors = IntArray(n) { if (it == 0) 0 else query("XOR", 0, it) }
    val answer = IntArray(n)
    val ix = IntArray(n)
    val time = IntArray(n)
    var t = 0
    var found = false
    for (mask in 0 until (n / 2)) {
        t++
        var a = Pair(-1, -1)
        for (j in 0 until n) {
            val x = mask and xors[j]
            if (time[x] == t) {
                a = Pair(ix[x], j)
                break
            } else {
                time[x] = t
                ix[x] = j
            }
        }
        if (a.first != -1) {
            t++
            var b = Pair(-1, -1)
            val nask = (n - 1) xor mask
            for (j in 0 until n) {
                val x = nask and xors[j]
                if (time[x] == t) {
                    b = Pair(ix[x], j)
                    break
                } else {
                    time[x] = t
                    ix[x] = j
                }
            }
            if (b.first != -1) {
                val y = query("AND", a.first, a.second) and mask
                val z = query("AND", b.first, b.second) and nask
                for (j in 0 until n) {
                    answer[j] = ((xors[j] xor xors[a.first] xor y) and mask) + ((xors[j] xor xors[b.first] xor z) and nask)
                }
                found = true
                break
            }
        }
    }
    if (!found) {
        throw IllegalStateException()
    }
    println("! " + answer.joinToString(" "))
}