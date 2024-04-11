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
		var A = readInts().toIntArray()
        var B = IntArray(n) {it}
		B = (B.sortedBy { A[it] }).toIntArray()
		var l = 0
		var r = n-1
		val res = ArrayList<Int>()
		//println(B.joinToString(" "))
		while(l <= r){
            var upTo = A[B[l]]
			if(l != 0)
				upTo--
			upTo = minOf(upTo, r-l+1)
			for(i in 0 until upTo){
				res.add(B[r]+1)
				r--
			}
			if(l <= r)
				res.add(B[l]+1)
			l++
		}
		println(res.joinToString(" "))
	}
}