import java.util.*

val MaxN = 200_000
val MaxM = 400_000

var N = 0
var M = 0
var E = 1
var K = 0
var Tp = 0
var Head = Array(MaxN + 5) {0}
var Next = Array(MaxM + 5) {0}
var To = Array(MaxM + 5) {0}
var Del = Array(MaxM + 5) {false}
var Deg = Array(MaxN + 5) {0}
var Stk = Array(MaxN + 5) {0}
var Ans = Array(MaxN + 5) { mutableListOf<Int>() }

fun addEdge(from: Int, to: Int) {
  E++;
  To[E] = to
  Next[E] = Head[from]
  Head[from] = E
}

fun dfs(u: Int) {
  while (Head[u] != 0) {
    if (Del[Head[u]] == false) {
      var v = To[Head[u]]
      Del[Head[u]] = true
      Del[Head[u] xor 1] = true
      dfs(v)
    }
    Head[u] = Next[Head[u]]
  }
  Tp++
  Stk[Tp] = u
}

var insTp = 0
var insStk = Array(MaxN + 5) {0}
var insVis = Array(MaxN + 5) {false}

fun ins() {
  if (Tp > 1) {
    insTp = 0
    for (i in 1 .. Tp) {
      var x = Stk[i]
      if (insVis[x] == true) {
        K++
        Ans[K].add(x)
        while (insTp > 0 && insStk[insTp] != x) {
          Ans[K].add(insStk[insTp])
          insVis[insStk[insTp]] = false
          insTp--
        }
        Ans[K].add(x)
      } else {
        insVis[x] = true;
        insStk[++insTp] = x
      }
    }
    for (i in 1 .. Tp) insVis[Stk[i]] = false
  }
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
  N = nextInt()
  M = nextInt()
  repeat(M) {
    var u = nextInt()
    var v = nextInt()
    addEdge(u, v)
    addEdge(v, u)
    Deg[u]++
    Deg[v]++
  }
  for (i in 1 .. N) {
    if (Deg[i] % 2 != 0) {
      println("NO")
      return
    }
  }
  K = 0
  for (i in 1 .. N) {
    Tp = 0
    dfs(i)
    ins()
  }
  println("YES")
  println(K)
  for (i in 1 .. K) {
    println("${Ans[i].size} " + Ans[i].joinToString(" "))
  }
}