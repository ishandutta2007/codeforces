import collection.immutable.IndexedSeq
import java.io.BufferedReader
import java.util.StringTokenizer

/**
 *
 * @author Vladislav Isenbaev (vladislav.isenbaev@odnoklassniki.ru)
 */

object CF152A extends App {

  def solve() {
    val n = nextInt()
    val m = nextInt()
    val lines = for (i <- 0 until n) yield in.nextLine()
    val courses = lines.map(_.map(_ - '0')).transpose
    val cool = new Array[Boolean](n)
    for (marks <- courses) {
      val max = marks.max
      for (i <- 0 until n if marks(i) == max) cool(i) = true
    }
    println(cool.count(identity[Boolean]))
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

  implicit val in = new Tokenizer(Console.in)
  implicit def nextInt()(implicit t: Tokenizer) = t.next(_.toInt)
  implicit def nextLong()(implicit t: Tokenizer) = t.next(_.toLong)
  implicit def nextDouble()(implicit t: Tokenizer) = t.next(_.toDouble)
  implicit def nextBigInt()(implicit t: Tokenizer) = t.next(BigInt(_))
  implicit def nextString()(implicit t: Tokenizer) = t.next(identity[String])

  def nextSeq[A](len: Int = nextInt())(implicit c: () => A): Seq[A] = for (i <- 0 until len) yield c()

  solve()

}