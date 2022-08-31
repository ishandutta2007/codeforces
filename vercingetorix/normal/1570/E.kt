fun main() {
    repeat(read()) {
        var s = readLine()!!.split("1")
        var ans = 0
        for(i in 1..s.size-2) ans += s[i].length
        println(ans)

    }
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}