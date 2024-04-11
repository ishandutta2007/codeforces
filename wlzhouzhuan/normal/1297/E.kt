import java.util.*
import kotlin.collections.HashMap
 
var scanner = Scanner(System.`in`)
 
fun readInt(): Int = scanner.nextInt()
fun readString(): String = scanner.next()
fun readInts() = readLine()!!.split(" ").map { it.toInt() }

var to = IntArray(800005)
var nxt = IntArray(800005)
var head = IntArray(800005)
var etot = 0

fun add(x: Int, y: Int) {
  etot++
  to[etot] = y
  nxt[etot] = head[x]
  head[x] = etot
}

var vis = IntArray(800005)
var deg = IntArray(800005)
var n = 0
var k = 0

var q = IntArray(800005)
var ql = 0
var qr = 0
var ans = IntArray(300005)

fun solve() {
  n = readInt()
  k = readInt()
  for (i in 1 .. n) head[i] = 0
  for (i in 1 .. 2 * n) to[i] = 0
  for (i in 1 .. 2 * n) nxt[i] = 0
  for (i in 1 .. n) deg[i] = 0
  for (i in 1 .. n) vis[i] = 1
  etot = 0
  for (i in 1 .. n - 1) {
    var x = readInt()
    var y = readInt()
    add(x, y)
    add(y, x)
    deg[x]++
    deg[y]++
  }
  ql = 0
  qr = 0
  for (i in 1 .. n) {
    if (deg[i] == 1) {
      q[qr++] = i;
    }
  }
  if (qr < k) {
    print("No\n")
    return 
  }
  if (qr == k) {
    print("Yes\n")
    print(n)
    print("\n")
    for (i in 1 .. n) {
      print(i)
      print(' ')
    }
    print("\n")
    return 
  }
  var zero = qr
  for (i in 1 .. n) {
    vis[i] = 1
  }
  for (_T in 0 .. n) {
    if (ql >= qr) {
      break
    }
    if (zero == k) {
      break
    }
    var u = q[ql++]
    vis[u] = 0
    //print("now: ")
    //print(u)
    //print("\n")
    
    var id = head[u]
    for (_id in 0 .. n) {
      var v = to[id]
      id = nxt[id]
      if (vis[v] == 1) {
        deg[v]--
        //print("update: ")
        //print(v)
        //print(" ")
        //print(deg[v])
        //print("\n")
        if (deg[v] != 1) {
            zero--
            if (zero == k) {
             break
            }
        }
        else {
          q[qr++] = v
        }
      }
      if (id == 0) {
        break
      }
    }
  }
  if (zero != k) {
    print("No\n")
  }
  print("Yes\n")
  var m = 0
  for (i in 1 .. n) {
    if (vis[i] == 1) {
      ans[++m] = i
    }
  } 
  //if (k == 1 && m > 1) {
  //  m--
  //}
  print(m)
  print("\n")
  for (i in 1 .. m) {
    print(ans[i])
    print(' ')
  }
  print("\n")
}

fun main() {
  var T = readInt()
  for (i in 1 .. T) {
    solve()
  }
}