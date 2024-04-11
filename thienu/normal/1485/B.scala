
object Main {
    def main(args: Array[String]) = {
        val Array(n, q, k) = readLine().split("\\s+").map(_.toInt)
        val a = readLine().split("\\s+").map(_.toInt)
        for (i <- 1 to q){
            // val l = sc.nextInt()
            // val r = sc.nextInt()
            var Array(l, r) = readLine().split("\\s+").map(_.toInt)
            l -= 1
            r -= 1
            val len = r - l + 1
            println((k - len) * 2 - (a(l) - 1) - (k - a(r)))
            // println(k - r + l)
        }
    }
}