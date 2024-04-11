import collection.mutable.ArrayBuffer
import io.Source
import java.io.PrintWriter

object CF288D {

  def solve(in: In, out: PrintWriter) {
    val n = in().toInt
    val edges = Array.fill(n)(ArrayBuffer.empty[Int])
    for (it <- 0 until n - 1) {
      val u, v = in().toInt - 1
//      val u = it
//      val v = it + 1
      edges(u) += v
      edges(v) += u
    }
    var ans = BigInt(0)
    def dfs(u: Int, p: Int): Long = {
      var size = 1L
      val d = Array.fill(2, 5)(0L)
      d(0)(0) = 1
      def regSubtree(s: Long) {
        for (i <- 1.to(0, -1); j <- 4.to(0, -1)) {
          if (i < 1) {
            d(i + 1)(j) += d(i)(j) * s * s
          }
          if (j < 4) {
            d(i)(j + 1) += d(i)(j) * s
          }
        }
      }
      var it = 0
      while (it < edges(u).size) {
        val v = edges(u)(it)
        if (v != p) {
          val sub = dfs(v, u)
          size += sub
          regSubtree(sub)
        }
        it += 1
      }
      if (p != -1) {
        regSubtree(n - size)
      }
//      out.println(u, d(1)(2), d(0)(4), d(1)(1), d(0)(3), d(1)(0), d(0)(2))
      ans += d(1)(2) * BigInt(2) + d(0)(4) * BigInt(12) + d(1)(1) * 2 + d(0)(3) * 12 + d(1)(0) + d(0)(2) * 4
      size
    }
    dfs(0, -1)
    assert(ans % 2 == 0)
    ans = BigInt(n.toLong * (n - 1) / 2) * (n.toLong * (n - 1) / 2) - ans / 2
    out.println(ans)
  }

  def main(args: Array[String]) {
    new Thread(null, new Runnable {
      def run() {
        val in: In = new In(Source.fromInputStream(System.in))
        val out: PrintWriter = new PrintWriter(System.out)
        solve(in, out)
        out.close()
      }
    }, "thread", 64000000).run()
  }

  class TokenIterator(iter: BufferedIterator[Char], delims: String) extends Iterator[String] {
    private val sb = new StringBuilder

    def hasNext: Boolean = {
      skipDelims()
      iter.hasNext
    }

    def skipDelims() {
      while (iter.hasNext && delims.indexOf(iter.head) != -1) {
        iter.next()
      }
    }

    def next(): String = {
      skipDelims()
      while (iter.hasNext && delims.indexOf(iter.head) == -1) {
        sb.append(iter.next())
      }
      val ret = sb.toString()
      sb.clear()
      ret
    }
  }

  class In(source: Source) {
    val iter = source.buffered

    val tokenIterator = new TokenIterator(iter, " \r\n")

    val lineIterator = new TokenIterator(iter, "\r\n")

    def apply() = tokenIterator.next()

    def apply(n: Int) = tokenIterator.take(n)
  }
}