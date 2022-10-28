fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }
    var mx = 0
    var oth = 0
    var ans = 0
    for (i in a) {
        if (i < oth) {
            ++ans;
        }
        if (i > mx) {
            oth = mx
            mx = i
        } else if (i > oth) {
            oth = i
        }
    }
    println(ans)
}