import io.Source
import java.io.PrintWriter
import scala.collection.mutable.ArrayBuffer

object CF292B {

  def solve(in: In, out: PrintWriter) {
    val n, m = in().toInt
    val ls = Array.fill(n)(0)
    for (it <- 0 until m) {
      val u, v = in().toInt - 1
      ls(u) += 1
      ls(v) += 1
    }
    out.println {
      if (ls.forall(_ == 2)) {
        "ring topology"
      } else if (ls.count(_ == 2) == n - 2 && ls.count(_ == 1) == 2) {
        "bus topology"
      } else if (ls.count(_ == 1) == n - 1 && ls.count(_ == n - 1) == 1) {
        "star topology"
      } else {
        "unknown topology"
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