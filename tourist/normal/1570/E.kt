fun main() {
    repeat(readInt()) {
        var s = readLine()!!
        val i = s.indexOf('1')
        if (i == -1) {
            println(0)
        } else {
            val j = s.lastIndexOf('1')
            val ans = s.substring(i until j).count {it == '0'}
            println(ans)
        }
    }
}

private fun readInt() = readLine()!!.toInt()
private fun readInts() = readLine()!!.split(" ").map {it.toInt()}