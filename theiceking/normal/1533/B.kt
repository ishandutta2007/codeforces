import kotlin.math.max
 
fun main() {
    val tc = readLine()!!.toInt()
    for (tt in tc - 1 downTo 0){
	    var ans = 0
	    val lol = readLine()!!.split(" ").map { it.toInt() }
	    val n = lol[0]
		val arr = readLine()!!.split(" ").map { it.toInt() }
	    for (i in n - 1 downTo 1) {
	    	var ret = (arr[i] - arr[i-1]) % 2
	    	
			if (ret == 0){
				ans =  1
			}
	    }
	    if (ans == 1) println("YES")
	    else println("NO")
    }
}