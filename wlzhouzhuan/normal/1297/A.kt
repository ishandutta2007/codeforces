import java.util.*
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readLong() = readLn().toLong()
fun readDouble() = readLn().toDouble()

fun main() {
  var T = readInt()
  for (t in 1 .. T) {
    var x = readInt()
    if (x <= 999) {
      println(x)
    } else if (x <= 999499) {
      println("${(x + 500) / 1000}K")
    } else {
      println("${(x + 500000) / 1000000}M")
    }
  }
}