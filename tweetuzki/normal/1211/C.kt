import java.util.Scanner

val MaxN = 200000

var N = 0; var K = 0L
var A = mutableListOf<Pair<Pair<Int, Int>, Int>>()

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
  N = nextInt(); K = nextLong()
  for (i in 1 .. N) {
    var a = nextInt(); var b = nextInt(); var c = nextInt()
    A.add(Pair(Pair(a, b), c))
  }
  A.sortBy({it.second})
  var ans = 0L
  for (i in 0 until N) {
    var a = A[i].first.first; var b = A[i].first.second; var c = A[i].second
    K -= a
    ans += 1L * a * c
  }
  if (K < 0) {
    println("-1")
    return
  }
  for (i in 0 until N) {
    var a = A[i].first.first; var b = A[i].first.second; var c = A[i].second
    var s: Long = (if (b - a < K) 1L * (b - a) else K)
    K -= s
    ans += 1L * s * c
  }
  if (K > 0) println("-1")
  else println(ans)
}