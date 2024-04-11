import java.util.*
import java.lang.Math;


fun main(args: Array<String>) {
    val T = readLine()!!.toInt()
    repeat(T) {
        val (n, k) = readLine()!!.split(" ").map( {it.toInt() })
        var ans = 0
        repeat(n) {
            val (l, r) = readLine()!!.split(" ").map( {it.toInt()})
            if(k >= l) {
                ans = Math.max(ans, r - k + 1);
            }
        }
        println(ans)
    }

}