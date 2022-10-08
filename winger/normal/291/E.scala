import io.Source
import java.io.PrintWriter

object CF291E {

  def solve(in: In, out: PrintWriter) {
//    val t0 = System.currentTimeMillis()
    val n = in().toInt
//    val n = 100000
    val par = Array.ofDim[Int](n)
    val strs = Array.ofDim[String](n)
    for (i <- 1 until n) {
      par(i) = in().toInt - 1
      strs(i) = in()
//      par(i) = i - 1
//      strs(i) = "a"
    }
    val str = in()
//    val str = "a" * 300000
    val p = Array.fill(str.size)(0)
    for (i <- 1 until str.length) {
      p(i) = p(i - 1)
      while (p(i) != 0 && str(i) != str(p(i))) {
        p(i) = p(p(i) - 1)
      }
      if (str(i) == str(p(i))) {
        p(i) += 1
      }
    }
    val q = Array.fill(n)(-1)
    q(0) = 0
    var ans = 0
    def eval(i: Int): Int = {
      if (q(i) == -1) {
        q(i) = eval(par(i))
        for (c <- strs(i)) {
          while (q(i) != 0 && c != str(q(i))) {
            q(i) = p(q(i) - 1)
          }
          if (c == str(q(i))) {
            q(i) += 1
          }
          if (q(i) == str.length) {
            ans += 1
            q(i) = p(q(i) - 1)
          }
        }
      }
      q(i)
    }
    (0 until n).foreach(eval)
    out.println(ans)
//    println(System.currentTimeMillis() - t0)
  }

  def main(args: Array[String]) {
    new Thread(null, new Runnable {
      def run() {
        val in: In = new In(Source.fromInputStream(System.in))
        val out: PrintWriter = new PrintWriter(System.out)
        solve(in, out)
        out.close()
      }
    }, "run", 128000000).run()
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