import java.io.BufferedReader
import java.util.StringTokenizer

/**
 *
 * @author Vladislav Isenbaev (vladislav.isenbaev@odnoklassniki.ru)
 */

object CF152B extends App {

  def main() {
    val n = nextInt()
    val m = nextInt()
    var x: Long = nextInt() - 1
    var y: Long = nextInt() - 1
    var ans = 0L
    for (it <- 0 until nextInt()) {
      val dx = nextInt()
      val dy = nextInt()
      val stepsX = if (dx == 0) Long.MaxValue else if (dx > 0) (n - x - 1) / dx else x / (-dx)
      val stepsY = if (dy == 0) Long.MaxValue else if (dy > 0) (m - y - 1) / dy else y / (-dy)
      val steps = stepsX min stepsY
      ans += steps
      x += dx * steps
      y += dy * steps
    }
    println(ans)
  }

  class Tokenizer(in: BufferedReader, pattern: String = " \t\n\r\f") {
    private def tokenizer = new StringTokenizer(_: String, pattern)
    var st: StringTokenizer = tokenizer("")
    def nextLine() = in.readLine()
    def nextToken(): String = {
      while (!st.hasMoreTokens) {
        val line = nextLine()
        if (line == null) return null
        st = tokenizer(line)
      }
      st.nextToken()
    }
    def next[A](f: String => A): A = f(nextToken())
  }

  implicit val tokenizer = new Tokenizer(Console.in)

  implicit def nextInt()(implicit t: Tokenizer) = t.next(_.toInt)
  implicit def nextLong()(implicit t: Tokenizer) = t.next(_.toLong)
  implicit def nextDouble()(implicit t: Tokenizer) = t.next(_.toDouble)
  implicit def nextBigInt()(implicit t: Tokenizer) = t.next(BigInt(_))
  implicit def nextString()(implicit t: Tokenizer) = t.next(identity[String])

  def nextSeq[A](len: Int = nextInt())(implicit c: () => A): Seq[A] = for (i <- 0 until len) yield c()

  main()
}