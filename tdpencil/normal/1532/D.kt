import java.util.*

fun main() {
    val T = 1
    repeat(T) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map({ it.toInt() }).toIntArray()
        Arrays.sort(a)

        var ans = 0
        for(i in 0 until n step 2) {
            ans += a[i+1]-a[i]
        }

        println(ans)
    }
}