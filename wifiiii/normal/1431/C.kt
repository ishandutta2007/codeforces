import kotlin.system.exitProcess

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { exitProcess(0); }

fun main() {
    var t = readi();
    while(t-- > 0) {
        var (n, k) = readii()
        var a = readii()
        var sum = ArrayList<Int>();
        sum.add(0)
        var cur = 0
        for(i in a) {
            cur += i
            sum.add(cur)
        }
        var ans = 0
        for(i in n-1 downTo 0) {
            var x = (n-i)/k
            ans = kotlin.math.max(ans, sum[i+x] - sum[i]);
        }
        println(ans)
    }
}