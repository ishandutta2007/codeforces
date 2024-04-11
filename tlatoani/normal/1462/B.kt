fun main() {
    for (c in 1..readLine()!!.toInt()) {
        readLine()
        val s = readLine()!!
        println(if ((0..4).any { s.startsWith("2020".substring(0, it)) && s.endsWith("2020".substring(it)) }) "yEs" else "nO")
    }
}