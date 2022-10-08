import io.Source
import java.io.PrintWriter

object CF292A {

  def solve(in: In, out: PrintWriter) {
    val n = in().toInt
    val ps = for (i <- 0 until n) yield {
      val t, c = in().toInt
      (t, c)
    }
    var t0, c0 = 0
    var maxSize = 0
    for ((t, c) <- ps.sorted) {
      val c1 = math.max(0, c0 - (t - t0)) + c
      maxSize = math.max(maxSize, c1)
      t0 = t
      c0 = c1
    }
    out.println((t0 + c0) + " " + maxSize)
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