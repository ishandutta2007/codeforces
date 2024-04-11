import java.util.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun <T>printColl(a : Collection<T>){
	for(x in a)
		print("$x ")
	println()
}

/*
toIntArray()
IntArray(sz) {initVal}
ArrayList<T>(...)
IntArrayOf(a, b, c)
minOf(x, y)
1 shl 10
println(res.joinToString(" "))
a.map {it.toString()}
l.toIntArray()
*/

fun main(){
    val (n, m, k) = readInts()
	val a = readInts()
	val dp = IntArray(n+2)
	var curI = n-1
	var curS = 0
	var res = 0
	for(i in n-1 downTo 0){
		curS += a[i]
		if(a[i] > k){
	    	dp[i] = m+2
		}
		else{
			while(curS > k){
				curS -= a[curI--]
			}
			dp[i] = dp[curI+1]+1
		}
		if(dp[i] <= m)
			res++
	}
	println(res)
}