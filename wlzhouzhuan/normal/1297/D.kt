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
  var T = readInt()
  while (T-- > 0) {
    val (n, k) = readLongs()
    val a = readLongs().withIndex().sortedByDescending{it.value}
    
    var l = a[0].value
    var r = a[0].value + k
    while (l < r) {
      var mid = (l + r) / 2
      var u = mid
      var left = k
      for (x in a) {
        left -= u - x.value
        u -= 1
      }
      if (left <= 0) r = mid
      else l = mid + 1
    }
    var ans = LongArray(n.toInt())
    var u = l
    var left = k
    
    for (x in a) {
      val d = minOf(left, u - x.value)
      left -= d
      ans[x.index] = d
      u -= 1
    }
    for (x in ans) {
      print("$x ")
    }
    println()
  }
}