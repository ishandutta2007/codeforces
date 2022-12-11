import java.util.Scanner

val MaxN = 5000

var N = 0
var A = Array(MaxN + 5) {0}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
  N = nextInt()
  for (i in 1 .. N) A[i] = nextInt()
  var mx = 0
  var mmx = 0
  var mmmx = 0
  for (i in 1 .. N) {
    if (A[i] == A[mx] || A[i] == A[mmx] || A[i] == A[mmmx]) continue
    if (A[i] > A[mx]) {
      mmmx = mmx
      mmx = mx
      mx = i
    } else if (A[i] > A[mmx]) {
      mmmx = mmx
      mmx = i
    } else if (A[i] > A[mmmx]) {
      mmmx = i
    }
  }
  if (mx == 0 || mmx == 0 || mmmx == 0) println("-1 -1 -1")
  else println("$mmmx $mmx $mx")
}