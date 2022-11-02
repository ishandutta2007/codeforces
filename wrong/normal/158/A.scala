object CF158A {
  def main(args: Array[String]) = {
    val sc = new java.util.Scanner(System.in)
    val n, k = sc.nextInt()
    val a = Array.fromFunction(_ => sc.nextInt())(n)

    println(a.count(
      x => x > 0 && a.count(y => y > x) < k
    ))
  }
}