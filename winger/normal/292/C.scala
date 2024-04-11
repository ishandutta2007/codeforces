import io.Source
import java.io.PrintWriter
import scala.collection.mutable.ArrayBuffer

object CF292C {

  val pow10 = Array(1, 10, 100)
  var ds = Array(0)
  var ans = ArrayBuffer.empty[Array[Int]]

  def gen2(ar: Array[Int], id: ArrayBuffer[Int], mul: ArrayBuffer[Int], i: Int, mask: Int) {
    val j = id.length - i - 1
    if (i > j) {
      if (Integer.bitCount(mask) == ds.length) {
        ans += ar.clone()
      }
    } else if (Integer.bitCount(mask) + (j - i) / 2 + 1 >= ds.length) {
      for (d <- ds if d != 0 || (i > 0 && id(i) == id(i - 1) || mul(i) == 1) && (id(j) == id(j - 1) || mul(j) == 1)) {
        ar(id(i)) += d * mul(i)
        if (i != j) {
          ar(id(j)) += d * mul(j)
        }
        if (ar(id(i)) < 256 && ar(id(j)) < 256) {
          gen2(ar, id, mul, i + 1, mask | (1 << d))
        }
        ar(id(i)) -= d * mul(i)
        if (i != j) {
          ar(id(j)) -= d * mul(j)
        }
      }
    }
  }

  def gen(lens: Array[Int], i: Int) {
    if (i == lens.length) {
      val id = ArrayBuffer.empty[Int]
      val mul = ArrayBuffer.empty[Int]
      for (i <- 0 until 4; j <- 0 until lens(i)) {
        id += i
        mul += pow10(lens(i) - j - 1)
      }
      gen2(Array.ofDim[Int](4), id, mul, 0, 0)
    } else {
      for (v <- 1 to 3) {
        lens(i) = v
        gen(lens, i + 1)
      }
    }
  }

  def solve(in: In, out: PrintWriter) {
    val n = in().toInt
    ds = Array.fill(n)(in().toInt)
    gen(Array.ofDim[Int](4), 0)
    out.println(ans.size)
    for (a <- ans) {
      out.println(a.mkString("."))
    }
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