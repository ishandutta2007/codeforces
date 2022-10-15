import java.util.*
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readLong() = readLn().toLong()
fun readDouble() = readLn().toDouble()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }
fun readDoubles() = readStrings().map { it.toDouble() }

var n = 0
var a = IntArray(0)
var b = IntArray(0)
var ans = 0

fun check(x: Int) {
  var cnt = 0
  for (i in 0 until n) {
    if (a[i] <= x && x <= b[i]) {
      cnt += 1
    }
  }
  if (cnt == 1) {
    ans = x
  }
}

fun main() {
  var T = readInt()
  while (T-- > 0) {
    n = readInt()
    a = IntArray(n)
    b = IntArray(n)
    for (i in 0 until n) {
      var (x, y) = readInts()
      a[i] = x
      b[i] = y
    }
    ans = -1
    for (i in 0 until n) {
      check(a[i])
      check(b[i])
      check(a[i] - 1)
      check(b[i] + 1)
    }
    println(ans)
  }
}