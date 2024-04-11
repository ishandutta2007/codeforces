fun main() {
    repeat(read()) {
        var n =read()
        var (a, va) =readv()
        var (c, vc) =readv()
        var b = read()
        var mn = maxOf(va, vc-c+b)
        var mx = minOf(vc, va + b-a)
        println("$mn")
    }
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}