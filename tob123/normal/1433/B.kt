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
		var mi=n+1
		var ma = 0
		var cnt = 0
		for(i in 0..n-1){
            if(A[i] == 1){
				mi = minOf(mi, i);
				ma = maxOf(ma, i);
				cnt++
			}
		}
		println(ma-mi+1-cnt)
	}
}