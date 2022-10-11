private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readDouble() = readLn().toDouble() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readDoubles() = readStrings().map { it.toDouble() } // list of ints

fun main(args: Array<String>) {
    val l = readInts()
    var ret = 0
    for(i in 0 until 200) {
        if(i <= l[0] && i+1 <= l[1] && i+2 <= l[2]) {
            ret = 3*i+3
        }
    }
    println(ret)
}