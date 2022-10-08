import io.Source
import java.io.PrintWriter

object CF291C {

  def solve(in: In, out: PrintWriter) {
    val n, k = in().toInt
    val a = {for (i <- 0 until n) yield {
      ((in().toLong * 256 + in().toLong) * 256 + in().toLong) * 256 + in().toLong
    }}.toArray
    var l = 0
    var r = 32
    var rVal = -1
    while (l + 1 < r) {
      val mid = (l + r) / 2
      val mask = ((1L << mid) - 1) << (32 - mid)
      val set = collection.mutable.HashSet[Long]()
      for (x <- a) {
        set += x & mask
      }
      if (set.size < k) {
        l = mid
      } else {
        r = mid
        rVal = set.size
      }
    }
    if (r == 32 || rVal != k) {
      out.println(-1)
    } else {
      val ans = ((1L << r) - 1) << (32 - r)
      out.print((ans >> 24) & 255)
      out.print(".")
      out.print((ans >> 16) & 255)
      out.print(".")
      out.print((ans >> 8) & 255)
      out.print(".")
      out.print((ans >> 0) & 255)
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

    val tokenIterator = new TokenIterator(iter, " .\r\n")

    val lineIterator = new TokenIterator(iter, "\r\n")

    def apply() = tokenIterator.next()

    def apply(n: Int) = tokenIterator.take(n)
  }
}