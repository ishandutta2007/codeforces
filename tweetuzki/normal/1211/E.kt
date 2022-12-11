import java.util.Scanner

val MaxN = 200_000

var N = 0
var A = Array(MaxN + 5) {0}
var Buc = Array(MaxN + 5) {0}
var Str = mutableListOf<Char>()
var Vis = Array(MaxN + 5) {false}

fun check(mid: Int): Boolean {
  Str.clear()
  var array_r = mutableListOf<Int>()
  var array_g = mutableListOf<Int>()
  for (i in 0 until N) {
    if (A[i] <= mid) {
      if (Vis[A[i]] == true) {
        Str.add('G')
        array_g.add(A[i])
      } else {
        Str.add('R')
        Vis[A[i]] = true
        array_r.add(A[i])
      }
    } else {
      Str.add('B')
    }
  }
  for (i in 1 .. mid) Vis[i] = false
  for (i in 0 until mid)
    if (array_r[i] != array_g[i]) return false
  return true
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
  N = nextInt()
  for (i in 0 until N) {
    A[i] = nextInt()
    Buc[A[i]]++
  }
  var lbound = 0; var rbound = 0; var ans = 0
  while (Buc[rbound + 1] == 2) rbound++
  while (lbound <= rbound) {
    var mid = (lbound + rbound) shr 1
    if (check(mid) == true) {
      ans = mid
      lbound = mid + 1
    } else {
      rbound = mid - 1
    }
  }
  check(ans)
  println(Str.joinToString(""))
}