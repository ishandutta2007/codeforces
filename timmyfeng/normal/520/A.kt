fun main() {
    val n = readLine()!!.toInt()
    val letters = mutableSetOf<Char>()
    for (i in readLine()!!.toLowerCase()) {
        letters.add(i)
    }
    println(if (letters.size == 26) "YES" else "NO")
}