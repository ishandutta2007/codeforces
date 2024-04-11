fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val t = readLine()!!

    val mismatch = mutableMapOf<Pair<Char, Char>, Int>()
    var hamming = 0
    for (i in s.indices) {
        if (s[i] != t[i]) {
            mismatch[s[i] to t[i]] = i
            ++hamming
        }
    }

    var two = -1 to -1
    var one = -1 to -1

    for ((pi, i) in mismatch) {
        for ((pj, j) in mismatch) {
            if (pi.first == pj.second && pi.second == pj.first) {
                two = i to j
            } else if (pi.first == pj.second || pi.second == pj.first) {
                one = i to j
            }
        }
    }

    if (two != -1 to -1) {
        println(hamming - 2)
        println("${two.first + 1} ${two.second + 1}")
    } else if (one != -1 to -1) {
        println(hamming - 1)
        println("${one.first + 1} ${one.second + 1}")
    } else {
        println(hamming)
        println("-1 -1")
    }
}