import io.Source
import java.io.PrintWriter

object CF291D {

  def solve(in: In, out: PrintWriter) {
    val n, k = in().toInt
    val a = Array.tabulate(n)(i => if (i == n - 1) 0 else 1)
    for (it <- 0 until k) {
      val vs = Array.fill(n + 1)(-1)
      for (i <- 0 until n) {
        vs(a(i)) = i
      }
      val max = a.max
      for (i <- 0 until n) {
        var j = math.min(max, n - i - 1 - a(i))
        while (vs(j) == -1) {
          j -= 1
        }
        out.print((vs(j) + 1) + " ")
        a(i) += j
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