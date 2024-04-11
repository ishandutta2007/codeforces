import java.util.TreeSet

fun main() {
    val powersOf2 = TreeSet((0..30).map { 1 shl it })
    repeat(readLine()!!.toInt()) {
        readLine()
        println(readLine()!!.split(" ").map { powersOf2.floor(it.toInt()) }.joinToString(" "))
    }
}