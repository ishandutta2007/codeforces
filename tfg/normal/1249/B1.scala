object Solution extends CodeForcesApp {
  import Utils._, annotation._, collection.{mutable, Searching}, util._, control._, math.Ordering.Implicits._, Searching._, Math._

  override def apply(io: IO): io.type = {
    val q = io.read[Int]
    for (i <- 0 until q) {
      val n = io.read[Int]
      var a = io.read[Array, Int](n)
      a = a.map(_ - 1)
      val ans = new Array[Int](n)
      for (i <- 0 until n) {
        if(a(i) != -1) {
          var size = 1
          var on = a(i)
          while(on != i) {
            size = size + 1;
            on = a(on)
          }
          while(on != -1) {
            ans(on) = size
            val nxt = a(on)
            a(on) = -1
            on = nxt
          }
        }
      }
      io.writeAll(ans)
      io.writeLine()
    }
    io
  }
}
/****************************[Ignore Template Below]****************************************/
trait CodeForcesApp {
  lazy val isOnlineJudge: Boolean = sys.props.get("ONLINE_JUDGE").exists(_.toBoolean)
  def debug(x: => Any): Unit = if (!isOnlineJudge) println(x)
  def apply(io: IO): io.type
  def main(args: Array[String]): Unit = apply(new IO(System.in, System.out)).close()
}
/****************************[Scala Collection Utils]****************************************/
object Utils {
  import scala.collection.mutable

  type of[C[_], A] = scala.collection.generic.CanBuild[A, C[A]]

  def when[A](check: Boolean)(f: => A): Option[A] = if (check) Some(f) else None

  def repeat[U](n: Int)(f: => U): Unit = (1 to n).foreach(_ => f)

  implicit class GenericExtensions[A](a: A) {
    def partialMatch[B](f: PartialFunction[A, B]): Option[B] = f lift a
  }

  implicit class TraversableExtensions[A, C[X] <: Traversable[X]](t: C[A]) {
    def zipWith[B](f: A => B)(implicit b: C of (A, B)): C[(A, B)] = (t map {i => i -> f(i)}).to[C]

    def whenNonEmpty[B](f: t.type => B): Option[B] = when(t.nonEmpty)(f(t))  // e.g. grades.whenNonEmpty(_.max)

    def toMultiSet: Map[A, Int] = t.groupBy(identity).mapValues(_.size)
  }

  implicit class PairExtensions[A, B](p: (A, B)) {
    def key = p._1
    def value = p._2
    def toSeq(implicit ev: B =:= A): Seq[A] = Seq(p.key, ev(p.value))
  }

  implicit class PairsExtensions[A, B, C[X] <: Traversable[X]](t: C[(A, B)]) {
    def toMultiMap(implicit b: C of B): Map[A, C[B]] = t.groupBy(_.key).mapValues(_.map(_.value).to[C]).withDefaultValue(b().result())
  }

  implicit class MapExtensions[K, V, C[X, Y] <: Map[X, Y]](m: C[K, V]) {
    def toMutable: mutable.Map[K, V] = mutable.Map.empty[K, V] ++ m
  }

  implicit class SetExtensions[A, C[A] <: Set[A]](s: C[A]) {
    def notContains(x: A): Boolean = !(s contains x)
    def toMutable = mutable.Set.empty[A] ++ s
  }

  implicit class IterableExtensions[A, C[A] <: Seq[A]](s: C[A]) {
    def indicesWhere(f: A => Boolean): Seq[Int] = s.zipWithIndex.collect {case (a, i) if f(a) => i}
    def deleteAtIndex(i: Int, howMany: Int = 1) = s.patch(i, Nil, howMany)
    def insertAtIndex(i: Int, items: Seq[A]) = s.patch(i, items, 0)
    def findWithIndex(f: A => Boolean): Option[(A, Int)] = s.zipWithIndex find {case (a, _) => f(a)}
  }

  implicit class BooleanExtensions(x: Boolean) {
    def to[A](implicit n: Numeric[A]) = if(x) n.one else n.zero
    def toEnglish = if(x) "Yes" else "No"
  }

  def desc[A](implicit order: Ordering[A]): Ordering[A] = order.reverse  //e.g. students.sortBy(_.height)(desc)

  def map[K] = new {
    def to[V](default: => V): mutable.Map[K, V] = using(_ => default)
    def using[V](f: K => V): mutable.Map[K, V] = new mutable.HashMap[K, V]() {
      override def apply(key: K) = getOrElseUpdate(key, f(key))
    }
  }

  def newMultiMap[K, V] = map[K] to mutable.Set.empty[V]

  def memoize[A, B](f: A => B): A => B = map[A] using f
}
/***********************************[Scala I/O]*********************************************/
import java.io._, java.util.StringTokenizer
import scala.collection.generic.CanBuild

class IO(in: BufferedReader, out: BufferedWriter) extends Iterator[String] with AutoCloseable with Flushable {
  def this(reader: Reader, writer: Writer) = this(new BufferedReader(reader), new BufferedWriter(writer))
  def this(in: InputStream, out: OutputStream) = this(new InputStreamReader(in), new OutputStreamWriter(out))

  private[this] val tokenizers = Iterator.continually(in.readLine()).takeWhile(_ != null).map(new StringTokenizer(_)).buffered
  val printer = new PrintWriter(out, true)

  @inline private[this] def tokenizer() = {
    while(tokenizers.nonEmpty && !tokenizers.head.hasMoreTokens) tokenizers.next()
    tokenizers.headOption
  }

  def read[A](implicit read: IO.Read[A]): A = read.apply(this)
  def read[C[_], A: IO.Read](n: Int)(implicit b: CanBuild[A, C[A]]): C[A] = Iterator.fill(n)(read).to[C]

  def readTill(delim: String): String = tokenizer().get.nextToken(delim)
  def readTillEndOfLine(): String = readTill("\n\r")

  def readAll[A: IO.Read]: (Int, Vector[A]) = {
    val data = read[Vector[A]]
    (data.length, data)
  }

  override def next() = tokenizer().get.nextToken()
  override def hasNext = tokenizer().nonEmpty

  def write(obj: Any): this.type = {
    printer.print(obj)
    this
  }
  def writeLine(): this.type = {
    printer.println()
    this
  }
  def writeLine(obj: Any): this.type = {
    printer.println(obj)
    this
  }
  def writeLines(obj: Traversable[Any]): this.type = writeAll(obj, separator = "\n")
  def writeAll(obj: Traversable[Any], separator: String = " "): this.type = write(obj mkString separator)
  def query[A: IO.Read](question: Any): A = writeLine(question).read

  override def flush() = printer.flush()
  def close() = {
    flush()
    in.close()
    printer.close()
  }
}
object IO {
  class Read[A](val apply: IO => A) {
    def map[B](f: A => B): Read[B] = new Read(apply andThen f)
  }

  object Read {
    implicit def collection[C[_], A: Read](implicit b: CanBuild[A, C[A]]) : Read[C[A]]         = new Read(r => r.read[C, A](r.read[Int]))
    implicit val string                                                   : Read[String]       = new Read(_.next())
    implicit val int                                                      : Read[Int]          = string.map(_.toInt)
    implicit val long                                                     : Read[Long]         = string.map(_.toLong)
    implicit val bigInt                                                   : Read[BigInt]       = string.map(BigInt(_))
    implicit val double                                                   : Read[Double]       = string.map(_.toDouble)
    implicit val bigDecimal                                               : Read[BigDecimal]   = string.map(BigDecimal(_))
    implicit def tuple2[A: Read, B: Read]                                 : Read[(A, B)]       = new Read(r => (r.read[A], r.read[B]))
    implicit def tuple3[A: Read, B: Read, C: Read]                        : Read[(A, B, C)]    = new Read(r => (r.read[A], r.read[B], r.read[C]))
    implicit def tuple4[A: Read, B: Read, C: Read, D: Read]               : Read[(A, B, C, D)] = new Read(r => (r.read[A], r.read[B], r.read[C], r.read[D]))
    implicit val boolean                                                  : Read[Boolean]      = string map {s =>
      s.toLowerCase match {
        case "yes" | "true" | "1" => true
        case "no" | "false" | "0" => false
        case _ => s.toBoolean
      }
    }
  }
}