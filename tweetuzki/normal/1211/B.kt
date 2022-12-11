import java.util.Scanner

val MaxN = 200000

var N = 0
var A = Array(MaxN + 5) {0}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
  N = nextInt()
  for (i in 1 .. N) A[i] = nextInt()
  var mx = 0
  for (i in 1 .. N) {
    if (A[i] >= A[mx])
      mx = i
  }
  var t = A[mx] - 1
  var ans = 1L * t * N + mx
  println(ans)
}