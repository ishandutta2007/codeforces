import io.Source
import java.io.PrintWriter
import scala.util.Random

object CF293A {

  def solve(in: In, out: PrintWriter) {
    val n = in().toInt
    val a, b = in()
    var c00, c01, c10, c11 = 0
    for (i <- 0 until a.length) {
      if (a(i) == '0') {
        if (b(i) == '0') {
          c00 += 1
        } else {
          c01 += 1
        }
      } else {
        if (b(i) == '0') {
          c10 += 1
        } else {
          c11 += 1
        }
      }
    }
    for (i <- 0 until n) {
      val d1 = if (c11 > 0) {
        c11 -= 1
        1
      } else if (c10 > 0) {
        c10 -= 1
        1
      } else if (c01 > 0) {
        c01 -= 1
        0
      } else if (c00 > 0) {
        c00 -= 1
        0
      } else {
        throw new AssertionError()
      }
      val d2 = if (c11 > 0) {
        c11 -= 1
        1
      } else if (c01 > 0) {
        c01 -= 1
        1
      } else if (c10 > 0) {
        c10 -= 1
        0
      } else if (c00 > 0) {
        c00 -= 1
        0
      } else {
        throw new AssertionError()
      }
      if (d1 != d2) {
        if (d1 > d2) {
          out.println("First")
        } else {
          out.println("Second")
        }
        return
      }
    }
    out.println("Draw")
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