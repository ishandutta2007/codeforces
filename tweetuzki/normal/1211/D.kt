import java.util.Scanner

val MaxN = 300_000
val MaxR = 1_000_000

var N = 0; var A = 0; var B = 0; var K = 0
var Buc = Array(MaxR + 5) {0}

fun min(a: Int, b: Int): Int {
  if (a < b) return a
  else return b
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
  N = nextInt(); A = nextInt(); B = nextInt(); K = nextInt()
  for (i in 0 until N) {
    var x = nextInt()
    Buc[x]++
  }
  var cnt = 0
  if (A < B) {
    for (i in MaxR downTo 1) {
      if (i % K == 0) {
        var j = i / K
        var s = min(Buc[j] / A, Buc[i] / B)
        cnt += s
        Buc[j] -= A * s
        Buc[i] -= B * s
      }
    }
  } else {
    for (i in 1 .. MaxR) {
      if (i * K <= MaxR) {
        var j = i * K
        var s = min(Buc[i] / A, Buc[j] / B)
        cnt += s
        Buc[i] -= A * s
        Buc[j] -= B * s
      }
    }
  }
  println(cnt)
}