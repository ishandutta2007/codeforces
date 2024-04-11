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
  /*
  val (n, m) = readInts()
	val a = readLongs()
	val G = Array(n) { mutableListOf<Pair<Int,Long>>() }
	for(i in 0 until m){
		var (x, y, w) = readLongs()
		x--
		y--
	}
  */
	val T = readInt()
	for(t in 0 until T){
		val n = readInt()
		var (mi, ma) = Pair(0, 1000*1000)
		for(i in 0 until n){
			var (s, t, m) = readLn().split(" ")
			var cnt = 0
			for(j in 0 until minOf(s.length, t.length)){
				if(s[s.length-j-1] == t[t.length-j-1])
					cnt++
				else
					break
			}
			if(m == "0")
				mi = maxOf(mi, cnt+1)
			else
				ma = minOf(ma, cnt)
		}
		if(mi > ma)
			println(0)
		else{
			val l = mutableListOf<Int>()
			println(ma-mi+1)
			for(x in mi..ma){
				l.add(x)
			}
			println(l.joinToString(" ") { "$it" })
		}
	}
}