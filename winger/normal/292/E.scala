import io.Source
import java.io.PrintWriter

object CF292E {

  def solve(in: In, out: PrintWriter) {
    val n, m = in().toInt
    val a = Array.fill(n)(in().toInt)
    val b = Array.fill(n)(in().toInt)
    val size = {
      var k = 1
      while (k < n) {
        k *= 2
      }
      k
    }
    val offset = Array.fill(size + n - 1)(-1)
    def update(n: Int, nl: Int, nr: Int, l: Int, r: Int, v: Int) {
      if (l <= nl && nr <= r) {
        offset(n) = v + nl - l
      } else if (r > nl && nr > l) {
        if (offset(n) != -1) {
          offset(2 * n + 1) = offset(n)
          offset(2 * n + 2) = offset(n) + (nr - nl) / 2
          offset(n) = -1
        }
        val mid = (nl + nr) / 2
        update(2 * n + 1, nl, mid, l, r, v)
        update(2 * n + 2, mid, nr, l, r, v)
      }
    }
    def get(n: Int, nl: Int, nr: Int, i: Int): Int = {
      if (offset(n) != -1) {
        a(offset(n) + (i - nl))
      } else if (nl + 1 == nr) {
        b(i)
      } else {
        val mid = (nl + nr) / 2
        if (i < mid) {
          get(2 * n + 1, nl, mid, i)
        } else {
          get(2 * n + 2, mid, nr, i)
        }
      }
    }
    for (it <- 0 until m) {
      if (in().toInt == 1) {
        val x, y = in().toInt - 1
        val k = in().toInt
        update(0, 0, size, y, y + k, x)
        //out.println(offset.deep)
      } else {
        out.println(get(0, 0, size, in().toInt - 1))
      }
    }
  }

  def main(args: Array[String]) {
    val in: In = new In(Source.fromInputStream(System.in))
    val out: PrintWriter = new PrintWriter(System.out)
    solve(in, out)
    out.close()
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