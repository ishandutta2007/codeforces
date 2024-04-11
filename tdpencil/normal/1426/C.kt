import java.util.*
import java.lang.Math;


fun main(args: Array<String>) {
    val T = readLine()!!.toInt()
    repeat(T) {
        val N = readLine()!!.toInt()
        var ans = 1000000000
        val V = Math.sqrt(N.toDouble())
        for(i in 1..(V+1).toInt()) {
            ans = ans.coerceAtMost((i - 1) + ((N + i - 1) / i) - 1);
        }
        println(ans)
    }
}