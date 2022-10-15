import java.util.*
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readLong() = readLn().toLong()
fun readDouble() = readLn().toDouble()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }
fun readDoubles() = readStrings().map { it.toDouble() }

fun main() {
  var t = readInt()
  while (t-- > 0) {
    var n = readInt()
    var a = readInts()
    var s = 0
    for (x in a) {
      s += maxOf(x, 0)
    }
    var t = CharArray(n)
    for (i in 0 until n) {
      t[i] = (if (a[i] > 0) '1' else '0')
    }
    var v = 1000000000
    var who = -1
    for (i in 0 until n) {
      if (a[i] > 0 && a[i] < v) {
        v = a[i]
        who = i
      }
      if (a[i] < 0 && -a[i] < v) {
        v = -a[i]
        who = i
      }
    }
    t[who] = (if (a[who] > 0) '0' else '1')
    println(s - v)
    println(t.joinToString(""))
  }
}