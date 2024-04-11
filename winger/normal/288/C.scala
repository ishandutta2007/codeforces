import io.Source
import java.io.PrintWriter

object CF288C {

  def solve(in: In, out: PrintWriter) {
    var n = in().toInt + 1
    val ans = Array.ofDim[Int](n)
    while (n > 1) {
      val m = 2 * Integer.highestOneBit(n - 1)
      out.flush()
      for (i <- m / 2 until n) {
        ans(i) = m - i - 1
        ans(m - i - 1) = i
      }
      n = m - n
    }
    var xor = 0L
    for (i <- 0 until ans.length) {
      xor += ans(i) ^ i
    }
    out.println(xor)
    out.println(ans.mkString(" "))
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