import java.util.*

val MaxN = 200000
var N = 0
var M = 0
var K = 0
var A = Array(MaxN + 5) {0L}
var Pre = Array(MaxN + 5) {0L}

fun sum(l: Int, r: Int): Long {
  return Pre[r] - Pre[l - 1]
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
  N = nextInt()
  M = nextInt()
  K = nextInt()
  for (i in 1 .. N) A[i] = nextLong()
  A.sort(1, N + 1)
  for (i in 1 .. N) Pre[i] = Pre[i - 1] + A[i]
  var ans = 1000000000000000000L
  for (l in 1 .. N - M + 1) {
    var r = l + M - 1
    var mi = (l + r) / 2
    if (A[mi] * (mi - l + 1) - sum(l, mi) <= K) {
      var res = A[mi] * (mi - l + 1) - sum(l, mi) + sum(mi, r) - A[mi] * (r - mi + 1)
      if (res < ans) ans = res
    } else {
      var lbound = l
      var rbound = r
      var anss = l
      while (lbound <= rbound) {
        var mid = (lbound + rbound) / 2
        if (A[mid] * (mid - l + 1) - sum(l, mid) <= K) {
          anss = mid;
          lbound = mid + 1
        } else {
          rbound = mid - 1
        }
      }
      var height = A[anss] + (K - (A[anss] * (anss - l + 1) - sum(l, anss))) / (anss - l + 1);
      var res = height * (anss - l + 1) - sum(l, anss) + sum(anss + 1, r) - height * (r - anss)
      if (res < ans) ans = res
    }
  }
  println(ans)
}