import java.util.*

val MaxN = 200_000

var Te = 0
var N = 0
var A = Array(MaxN + 5) {0}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
  Te = nextInt()
  repeat(Te) {
    N = nextInt()
    for (i in 1 .. N) A[i] = nextInt()
    A.sort(1, N + 1)
    var mid = N shr 1
    var cnt = 0
    var pointer_a = mid
    var pointer_b = mid + 1
    while (pointer_a > 0) {
      if (A[pointer_a] != A[mid]) break
      pointer_a--
      cnt++
    }
    while (pointer_b <= N) {
      if (A[pointer_b] != A[mid]) break
      pointer_b++
      cnt++
    }
    var arr = mutableListOf<Int>()
    if (cnt <= N / 2) {
      for (i in (mid + 1) .. N) {
        arr.add(A[i])
        if (i - mid <= mid) arr.add(A[i - mid])
      }
    } else {
      for (i in 1 .. pointer_a) {
        arr.add(A[mid])
        arr.add(A[i])
      }
      if (pointer_a == 0 || pointer_b == N + 1) arr.add(A[mid])
      for (i in pointer_b .. N) {
        arr.add(A[i])
        arr.add(A[mid])
      }
    }
    println("${arr.size}")
    println(arr.joinToString(" "))
    for (k in 1 .. N) A[k] = 0
  }
}