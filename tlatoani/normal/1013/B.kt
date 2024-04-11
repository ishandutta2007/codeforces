fun main() {
    val (n, x) = readLine()!!.split(" ").map { it.toInt() }
    val a = readLine()!!.split(" ").map { it.toInt() }
    val aSet = a.toSet()
    if (a.toSet().size < n) {
        println(0)
    } else if (a.map { it and x }.toSet().size < n) {
        var any = false
        for (j in a) {
            if (j and x != j && j and x in aSet) {
                any = true
            }
        }
        println(if (any) 1 else 2)
    } else {
        println(-1)
    }
}