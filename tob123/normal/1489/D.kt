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
	var s = mutableListOf<String>()
	for (t in 1..T){
		s.add(readLn())
	}
	s.sortBy { it.length }
	var works = true
	for(i in 1 until T){
		works = works && s[i].contains(s[i-1])
	}
	if(works){
		println("YES")
		for(x in s)
			println(x)
	}
	else
		println("NO")
}