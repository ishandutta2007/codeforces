import io.Source
import java.io.PrintWriter

object CF288B {
  
  val MOD = 1000000007L
  val MAX = 1000

  def modPow(x: Long, pow: Int): Long = {
    if (pow == 0) {
      1
    } else {
      val r = modPow((x * x) % MOD, pow / 2)
      if (pow % 2 == 1) {
        (r * x) % MOD
      } else {
        r
      }
    }
  }

  val c = Array.ofDim[Long](MAX + 1, MAX + 1)

  {
    for (i <- 0 to MAX) {
      for (j <- 1 until i) {
        c(i)(j) = (c(i - 1)(j - 1) + c(i - 1)(j)) % MOD
      }
      c(i)(0) = 1
      c(i)(i) = 1
    }
  }

  val fact = Array.ofDim[Long](MAX + 1)

  {
    fact(0) = 1
    for (i <- 1 to MAX) {
      fact(i) = (fact(i - 1) * i) % MOD
    }
  }

  def solve(in: In, out: PrintWriter) {
    val n, k = in().toInt
    var ans = 0L
    //C(k-1, t-1)*(t-1)!*k^(k-t-2)
    for (t <- 1 to k) {
      var add = (c(k-1)(t-1) * fact(t - 1)) % MOD
      add = (add * modPow(k, k - t - 1)) % MOD
      if (t < k) add = (add * t) % MOD
//      out.println(t + " " + add)
      ans = (ans + add) % MOD
    }
    ans = (ans * modPow(n - k, n - k)) % MOD
    out.println(ans)
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