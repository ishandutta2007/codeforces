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
		val x = readLn()
		val len = x.length
		val c = x[0]
        var i = '1'
		var res : Long = 0
        while(i < c){
            for(j in 1..4)
				res += j
			i++
		}
		for(j in 1..len)
			res += j
		println(res)
	}
}