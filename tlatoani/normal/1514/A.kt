fun main() {
    for (c in 1..readLine()!!.toInt()) {
        readLine()!!
        println(if (readLine()!!.split(" ").map { it.toInt() }.any { x -> !(1..100).any { y -> y * y == x } }) "YES" else "NO")
    }
}