fun main() {
    cases@for (c in 1..readLine()!!.toInt()) {
        val s = readLine()!!
        val t = readLine()!!
        for (a in 1..t.length) {
            for (b in 1..s.length) {
                if (s.repeat(a) == t.repeat(b)) {
                    println(s.repeat(a))
                    continue@cases
                }
            }
        }
        println(-1)
    }
}