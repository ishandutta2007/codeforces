import kotlin.math.max
 
fun main() {
    val tc = readLine()!!.toInt()
    for (tt in tc - 1 downTo 0){
	    var ans = 0L
	    val lol = readLine()!!.split(" ").map { it.toLong() }
	    val n = lol[0]
	    val k = lol[1]
	    
	    for (i in n - 1 downTo 0) {
			val ay = readLine()!!.split(" ").map { it.toLong() }
			val a1 = ay[0] 
			val a2 = ay[1]
			if (k >= a1){
				ans = max(ans, a2 - k + 1)
			}
	    }
	    println(ans); 
    }
}