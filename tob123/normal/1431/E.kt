import java.lang.Math.abs
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
		val A = readInts()
		val B = readInts()
		var res = -1
		var resI = 0
        for(i in 0 until n){
			var cur = 100000000
			for(j in 0 until n){
				cur = minOf(cur, abs(A[j] - B[(j + i) % n]))
			}
            if(cur > res){
				res = cur
				resI = i
			}
		}
		val X = ArrayList<Int>()
        for(i in 0 until n){
			X.add((i+resI)%n+1)
		}
		println(X.joinToString(" "))
	}
}