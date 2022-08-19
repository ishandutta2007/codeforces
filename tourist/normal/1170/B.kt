fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }
    var m1 = 0
    var m2 = 0
    var ans = 0
    for (c in a) {
        if (c > m1) {
            m2 = m1
            m1 = c
        } else {
            if (c >= m2) {
                m2 = c
            } else {
                ans++
            }
        }
    }
    println(ans)
}