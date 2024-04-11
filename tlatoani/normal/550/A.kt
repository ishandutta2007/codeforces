fun main() {
    val s = readLine()!!
    println(if (s.indexOf("AB") in 0..s.lastIndexOf("BA") - 2 || s.indexOf("BA") in 0..s.lastIndexOf("AB") - 2) "YES" else "NO")
}