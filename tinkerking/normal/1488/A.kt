/**
 * You can edit, run, and share this code. 
 * play.kotlinlang.org 
 */
fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
    	val (x, y) = readLine()!!.split(" ").map { it.toLong() }
    	var ans = y % x
    	var tmp = y / x
    	while(tmp > 0) {
    	    ans += tmp % 10
    	    tmp /= 10
    	}
    	println(ans)
    }
}