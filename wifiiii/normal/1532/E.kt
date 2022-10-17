import java.util.*

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}

var cnt = IntArray(1000005);
fun main() {
    var n = readi()
    var a = readii()
    var sum:Long = 0
    for (i in a) {
        cnt[i] += 1;
        sum += i
    }
    var ans = ArrayList<Int>();
    a.forEachIndexed { index, i ->
        sum -= i
        cnt[i] -= 1
        if(sum % 2 == 0L && sum / 2 <= 1000000) {
            var tmp:Int = (sum / 2).toInt()
            if(cnt[tmp] > 0) {
                ans.add(index + 1)
            }
        }
        cnt[i] += 1
        sum += i
    }
    println(ans.size)
    ans.forEach { print("$it ") }
}