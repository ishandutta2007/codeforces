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
		val (n, k) = readInts()
		val P = readInts()
		var best = 0
		for(i in 1..n){
			var sum = 0
			for(j in 0 until i/k){
				sum += P[n-i+j]
			}
			best = maxOf(best, sum)
		}
		println(best)
	}
}