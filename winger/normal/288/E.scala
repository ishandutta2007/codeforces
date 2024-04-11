import io.Source
import java.io.PrintWriter

object CF288E {

  val MOD = 1000000007L

  case class D(u: Long, v: Long, w: Long, first: Long, last: Long) {
    def combine(o: D) = {
      D(
        (u + o.u + 1) % MOD,
        (v + o.v + last + o.first) % MOD,
        (w + o.w + last * o.first) % MOD,
        first,
        o.last
      )
    }

    def shift(add: Long) = {
      D(u, (v + 2 * (u * add % MOD)) % MOD, (w + (u * (add * add % MOD) % MOD) + v * add) % MOD, (first + add) % MOD, (last + add) % MOD)
    }
  }

  def solve(in: In, out: PrintWriter) {
    val s1, s2 = in()
    if (s1 == s2) {
      out.println(0)
      return
    }
    val n = s1.size
    val d = Array.ofDim[D](n)
    d(0) = D(0, 0, 0, 0, 0)
    val pow10 = Array.ofDim[Long](n + 1)
    pow10(0) = 1
    for (i <- 1 to n) {
      pow10(i) = (pow10(i - 1) * 10) % MOD
    }
    for (i <- 1 until n) {
      d(i) = d(i - 1).shift((4 * pow10(i - 1)) % MOD).combine(d(i - 1).shift((7 * pow10(i - 1)) % MOD))
    }
    def ss(s: String) = {
      val r = Array.ofDim[Long](n + 1)
      for (i <- 0 until n) {
        r(i + 1) = (r(i) * 10 + s(i) - '0') % MOD
      }
      for (i <- 0 to n) {
        r(i) = (r(i) * pow10(n - i)) % MOD
      }
      r
    }
    val s1s = ss(s1)
    val s2s = ss(s2)
    var ans: D = D(0, 0, 0, s1s(n), s1s(n))
    var fd = 0
    while (s1(fd) == s2(fd)) {
      fd += 1
    }
//    out.println(d.deep, s1s.deep, s2s.deep, ans)
    assert(s1(fd) == '4' && s2(fd) == '7')
    for (i <- (n - 1).until(fd, -1)) {
      if (s1(i) == '4') {
        val shift: D = d(n - i - 1).shift((s1s(i) + 7 * pow10(n - i - 1)) % MOD)
        ans = ans.combine(shift)
//        out.println(shift, ans)
      }
    }
    val it4 = Array.ofDim[Long](n + 1)
    it4(0) = 0
    for (i <- 1 to n) {
      it4(i) = (it4(i - 1) * 10 + 4) % MOD
    }
    for (i <- (fd + 1) until n) {
      if (s2(i) == '7') {
        val shift: D = d(n - i - 1).shift((s2s(i) + 4 * pow10(n - i - 1)) % MOD)
        ans = ans.combine(shift)
//        out.println(shift, ans)
      }
    }
    val shift: D = D(0, 0, 0, s2s(n), s2s(n))
    ans = ans.combine(shift)
//    out.println(shift, ans)
    out.println(ans.w)
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