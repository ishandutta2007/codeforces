fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!

    var i = 0
    var ptr = 0
    while (ptr < n) {
        print(s[ptr])
        ptr += ++i
    }

    println()
}