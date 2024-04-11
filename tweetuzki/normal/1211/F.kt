import java.util.Scanner

val MaxN = 100_000

var N = 0

fun dict(x: Char): Int {
  if (x == 'k') return 0
  if (x == 'o') return 1
  if (x == 't') return 2
  if (x == 'l') return 3
  if (x == 'i') return 4
  if (x == 'n') return 5
  return -1
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
  N = nextInt()
  nextLine()
  for (i in 1 .. N) {
    var s = nextLine()
    var len = s.length
    var bg = dict(s[0])
    var ed = dict(s[len - 1])
    addEdge(bg, (ed + 1) % 6)
  }
  dfs(0)
  Res.reverse()
  println(Res.joinToString(" "))
}

var E = 0
var Head = Array(6) {0}
var Next = Array(MaxN + 5) {0}
var To = Array(MaxN + 5) {0}
var Res = mutableListOf<Int>()

fun addEdge(from: Int, to: Int) {
  E++
  To[E] = to
  Next[E] = Head[from]
  Head[from] = E
}

fun dfs(u: Int) {
  while (Head[u] > 0) {
    var v = To[Head[u]]
    var e = Head[u]
    Head[u] = Next[Head[u]]
    dfs(v)
    Res.add(e)
  }
}