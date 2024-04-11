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
		var s = readLn()
        s = s + "w"
		var res = 0
		var cnt = 0
		for(c in s){
			if(c == 'w'){
				res += cnt/2 + 1
				cnt = 0
			}
			else{
				cnt++
			}
		}
		println(res-1)
	}
}