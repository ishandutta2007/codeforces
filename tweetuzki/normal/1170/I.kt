import java.util.*

val MaxN = 400_000
val MaxV = 1_048_576
val Mod = 998_244_353

fun add(x: Int, y: Int): Int {
  var z = x + y
  if (z >= Mod) z -= Mod
  return z
}

fun mul(x: Int, y: Int): Int {
  return (1L * x * y % Mod).toInt()
}

fun pw(_x: Int, _y: Int): Int {
  var z = 1
  var y = _y
  var x = _x
  while (y != 0) {
    if (y % 2 == 1) z = mul(z, x)
    y = y shr 1
    x = mul(x, x)
  }
  return z
}

var N = 0
var V = 0
var A = mutableListOf<Pair<Int, Int>>()
var Coef = 1

fun disp() {
  var d = Array(MaxN + 5) {0}
  for (i in 0 until N) {
    d[i + 1] = A[i].first
    d[i + 1 + N] = A[i].second
  }
  d.sort(1, N * 2 + 1)
  for (i in 0 until N) {
    var lbound = 1
    var rbound = N * 2
    var ansfirst = 0
    var anssecond = 0
    while (lbound <= rbound) {
      var mid = (lbound + rbound) shr 1
      if (d[mid] >= A[i].first) {
        ansfirst = mid
        rbound = mid - 1
      } else {
        lbound = mid + 1
      }
    }
    lbound = 1
    rbound = N * 2
    while (lbound <= rbound) {
      var mid = (lbound + rbound) shr 1
      if (d[mid] >= A[i].second) {
        anssecond = mid
        rbound = mid - 1
      } else {
        lbound = mid + 1
      }
    }
    A[i] = Pair(ansfirst, anssecond)
    if (anssecond > V) V = A[i].second
  }
}

fun eraseBound() {
  var dif = Array(MaxN + 5) {0}
  var buc = Array(MaxN + 5) {0}
  for (i in 0 until N) {
    dif[A[i].first]++
    dif[A[i].second]--
    if (A[i].first == A[i].second) buc[A[i].first]++
  }
  var last_empty = 1
  for (i in 1 .. V) {
    dif[i] += dif[i - 1]
    // println("i = $i, dif = ${dif[i]}, buc = ${buc[i]}, last_empty = $last_empty")
    if (dif[i] != 0) {
      if (last_empty < i) {
        N++
        A.add(Pair(last_empty, i))
      }
      last_empty = i + 1
    }
    if (dif[i] == 0 && dif[i - 1] == 0) {
      if (buc[i] != 0) Coef = mul(Coef, pw(2, buc[i]) - 1)
    } else {
      Coef = mul(Coef, pw(2, buc[i]))
    }
  }
  while (V > 1 && dif[V - 1] == 0) V--
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
  N = nextInt()
  for (i in 1 .. N) {
    var x = nextInt()
    var y = nextInt()
    A.add(Pair(x, y))
  }
  disp()
  eraseBound()
  A.sortBy({it.second})
  // println("output")
  // for (i in 0 until N)
  //   println("i = $i, ${A[i]}")
  // println("Coef = $Coef, V = $V")
  buildTree(1, V, 1)
  updatePos(1, 1, 1)
  for (i in 0 until N) {
    // if (i % 100 == 0) println("start $i")
    var l = A[i].first
    var r = A[i].second
    if (l == r) continue
    updateRange(1, l - 1, 2, 1)
    var s = queryTree(l, r, 1)
    updatePos(r, s, 1)
    // for (j in 1 .. V)
    //   println("f[${i + 1}][$j] = ${queryTree(j, j, 1)}")
  }
  var ans = queryTree(V, V, 1)
  ans = mul(ans, Coef)
  println(ans)
}

var L = Array(MaxV + 5) {0}
var R = Array(MaxV + 5) {0}
var Sum = Array(MaxV + 5) {0}
var Tag = Array(MaxV + 5) {1}

fun buildTree(left: Int, right: Int, i: Int) {
  L[i] = left
  R[i] = right
  if (L[i] == R[i]) return
  var mid = (L[i] + R[i]) shr 1
  buildTree(left, mid, i shl 1)
  buildTree(mid + 1, right, (i shl 1) or 1)
}

fun upt(i: Int, v: Int) {
  Sum[i] = mul(Sum[i], v)
  Tag[i] = mul(Tag[i], v)
}

fun pushDown(i: Int) {
  if (Tag[i] != 1) {
    upt(i shl 1, Tag[i])
    upt((i shl 1) or 1, Tag[i])
    Tag[i] = 1
  }
}

fun updatePos(pos: Int, weight: Int, i: Int) {
  if (L[i] == R[i]) {
    Sum[i] = add(Sum[i], weight)
    return
  }
  pushDown(i)
  var mid = (L[i] + R[i]) shr 1
  if (pos <= mid) {
    updatePos(pos, weight, i shl 1)
  } else {
    updatePos(pos, weight, (i shl 1) or 1)
  }
  Sum[i] = add(Sum[i shl 1], Sum[(i shl 1) or 1])
}

fun updateRange(left: Int, right: Int, weight: Int, i: Int) {
  if (left > right) return
  if (left == L[i] && right == R[i]) {
    upt(i, weight)
    return
  }
  pushDown(i)
  var mid = (L[i] + R[i]) shr 1
  if (right <= mid) {
    updateRange(left, right, weight, i shl 1)
  } else if (left > mid) {
    updateRange(left, right, weight, (i shl 1) or 1)
  } else {
    updateRange(left, mid, weight, i shl 1)
    updateRange(mid + 1, right, weight, (i shl 1) or 1)
  }
  Sum[i] = add(Sum[i shl 1], Sum[(i shl 1) or 1])
}

fun queryTree(left: Int, right: Int, i: Int): Int {
  if (left > right) return 0
  if (left == L[i] && right == R[i]) return Sum[i]
  pushDown(i)
  var mid = (L[i] + R[i]) shr 1
  if (right <= mid) {
    return queryTree(left, right, i shl 1)
  } else if (left > mid) {
    return queryTree(left, right, (i shl 1) or 1)
  } else {
    var lc = queryTree(left, mid, i shl 1)
    var rc = queryTree(mid + 1, right, (i shl 1) or 1)
    return add(lc, rc)
  }
}