private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    var n = readInt()
    var s = readLn()
    val alpha = 26
    var cnt = Array(alpha, {IntArray(alpha, {0})})
    for (i in 0..n-2) {
        cnt[s[i] - 'A'][s[i + 1] - 'A']++
    }
    var mx = 0
    var res = ""
    for (i in 0..alpha-1) {
        for (j in 0..alpha-1) {
            if (cnt[i][j] > mx) {
                mx = cnt[i][j]
                res = ""
                res += 'A' + i
                res += 'A' + j
            }
        }
    }
    println(res)
}