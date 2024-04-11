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
/*
fun getElem(oth: Set<Int>, pq: PriorityQueue<Pair<Long, Int>>): Pair<Long,Int>?{
	var p1: Pair<Long, Int>? = null
	while(pq.isNotEmpty()) {
		val (c, ind) = pq.poll()
		if(oth.contains(ind)){
			p1 = Pair(c, ind)
			break
		}
	}
    return p1
}
*/

fun main(){
	val T = readInt()
	for(t in 0 until T) {
		val n = readInt()
		val (a, va) = readInts()
		val (c, vc) = readInts()
		val b = readInt()
		val res = if (b == c-1) maxOf(va, vc-1)
		else
			minOf(vc, va+b-a)
		println(res)
	}
}