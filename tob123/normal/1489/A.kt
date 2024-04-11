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
    val n = readInt()
	val a = readInts()
	val r = a.reversed()
	val cur = mutableListOf<Int>()
	val vals = mutableSetOf<Int>()
	for(x in r){
		if(!vals.contains(x)) {
			cur.add(x)
			vals.add(x)
		}
	}
	val res = cur.reversed()
	println(res.size)
	printColl(res)
}