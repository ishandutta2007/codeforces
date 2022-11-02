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
	val T = readInt()
	for (t in 1..T){
		val n = readInt()
		val A = readInts().toIntArray()
		val ma = A.max()!!
		val mi = A.min()!!
		var res = -1
		for(i in 0 until n){
			if(A[i] == ma && ((i > 0 && A[i-1] != A[i]) || (i<n-1 && A[i+1] != A[i])))
				res = i
		}
		if(mi == ma){
			println(-1)
		}
		else
			println(res+1)
	}
}