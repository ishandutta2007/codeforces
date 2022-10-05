fun main() {
    var s = ""
    for (j in 0..15) {
        if (j == 0 || j == 4 || j == 12) {
            s += "dbdcdcddcdcd"
        } else {
            s += "dadcdcddcdcd"
        }
    }
    readLine()
    val t = readLine()!!.split(" ").map { "abcd"[it.toInt() - 28] }.joinToString("")
    println(if (s.contains(t)) "yEs" else "nO")
}