fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        val ds = mutableSetOf<Int>()
        for (x in xs) {
            for (y in xs) {
                ds.add(y - x)
            }
        }
        println(ds.size / 2)
    }
}