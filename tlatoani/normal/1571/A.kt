fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val x = s.toSet()
        println(when {
            x == setOf('=') -> '='
            '>' !in x -> '<'
            '<' !in x -> '>'
            else -> '?'
        })
    }
}