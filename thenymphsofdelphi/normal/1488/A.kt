private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(args: Array<String>) {
    val q = readInt()
    for (qq in 1..q){
        var (x, y) = readLongs()
        var ans = 0L
        for (p in 9 downTo 0){
            var t = 1L
            for (i in 1..p){
                t = t * 10
            }
            t = t * x
            while (y >= t){
                ans = ans + 1
                y = y - t
            }
        }
        ans = ans + y
        println(ans)
    }
}