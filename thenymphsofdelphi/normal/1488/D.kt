import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(args: Array<String>) {
    val q = readInt()
    repeat(q){
        val (n, s) = readLongs()
        var l = 1L; var r = 1000000000000000000L
        while (l < r){
            var mid = (l + r + 1) / 2
            var x = mid; var sum = mid; var tn = n - 1
            while (tn > 0 && x > 1){
                x = (x + 1) / 2; sum = sum + x; tn = tn - 1;
            }
            sum = sum + tn;
            if (sum <= s){
                l = mid
            }
            else{
                r = mid - 1
            }
        }
        println(l)
    }
}