import io.Source
import java.io.PrintWriter
import scala.collection.mutable.ArrayBuffer

object CF292D {

  class DJU(n: Int) {
    val p = Array.tabulate(n)(identity)
    val r = Array.fill(n)(0)

    def get(i: Int): Int = {
      if (p(i) == i) {
        i
      } else {
        p(i) = get(p(i))
        p(i)
      }
    }

    def join(i: Int, j: Int): Boolean = {
      val u = get(i)
      val v = get(j)
      if (u == v) {
        false
      } else {
        if (r(u) < r(v)) {
          p(u) = v
        } else {
          p(v) = u
        }
        if (r(u) == r(v)) {
          r(u) += 1
        }
        true
      }
    }

    def reset() {
      for (i <- 0 until n) {
        p(i) = i
        r(i) = 0
      }
    }
  }

  def solve(in: In, out: PrintWriter) {
    val n, m = in().toInt
    val x, y = Array.ofDim[Int](m)
    for (i <- 0 until m) {
      x(i) = in().toInt - 1
      y(i) = in().toInt - 1
    }
    val left_, right_ = ArrayBuffer.empty[Int]
    val d = new DJU(n)
    for (i <- 0 until m) {
      if (d.join(x(i), y(i))) {
        left_ += i
      }
    }
    d.reset()
    for (i <- m - 1 to (0, -1)) {
      if (d.join(x(i), y(i))) {
        right_ += i
      }
    }
    val left = left_.toArray
    val right = right_.toArray
    val k = in().toInt
    for (it <- 0 until k) {
      val l, r = in().toInt - 1
      d.reset()
      var ans = n
      var it = 0
      while (it < left.length && left(it) < l) {
        val i = left(it)
        it += 1
        if (d.join(x(i), y(i))) {
          ans -= 1
        }
      }
      it = 0
      while (it < left.length && right(it) > r) {
        val i = right(it)
        it += 1
        if (d.join(x(i), y(i))) {
          ans -= 1
        }
      }
      out.println(ans)
    }
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