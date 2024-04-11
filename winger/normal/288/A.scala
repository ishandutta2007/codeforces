import io.Source
import java.io.PrintWriter

object CF288A {

  def solve(in: In, out: PrintWriter) {
    val n, k = in().toInt
    if (n < k || k == 1 && n > 1) {
      out.println("-1")
    } else {
      for (i <- 0 until math.min(n, n - (k - 2))) {
        out.print(if (i % 2 == 0) 'a' else 'b')
      }
      for (i <- 2 until k) {
        out.print((i + 'a').toChar)
      }
      out.println()
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