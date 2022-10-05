import java.lang.StringBuilder

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val last = ('a'..'z').filter { it in s }.map { s.lastIndexOf(it) }.min()!!
        out.appendln(s.substring(last))
    }
    print(out)
}