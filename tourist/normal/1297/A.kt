private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    for (q in 0..t-1) {
        var n = readInt()
        if (n < 1000) {
            println(n)
        } else {
            if (n >= 999500) {
                if (n % 1000000 >= 500000) {
                    n = n - n % 1000000 + 1000000
                } else {
                    n = n - n % 1000000
                }
                println("${n / 1000000}M")
            } else {
                if (n % 1000 >= 500) {
                    n = n - n % 1000 + 1000
                } else {
                    n = n - n % 1000
                }
                println("${n / 1000}K")
            }
        }
    }
}