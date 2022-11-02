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

fun main(){
    val (n, m) = readInts()
	val a = readLongs()
	val G = Array(n) { mutableListOf<Pair<Int,Long>>() }
	for(i in 0 until m){
		var (x, y, w) = readLongs()
		x--
		y--
        G[x.toInt()].add(Pair(y.toInt(), w))
		G[y.toInt()].add(Pair(x.toInt(), w))
	}
    var res: Long = 0
	val pqComparator: Comparator<Pair<Long, Int>> = compareBy { it.first }
	val PQ = PriorityQueue<Pair<Long,Int>>(pqComparator)
	val pqOth = PriorityQueue<Pair<Long,Int>>(pqComparator)
	PQ.add(Pair(0L, 0))
	val oth = mutableSetOf<Int>()
	for(i in 0 until n){
		oth.add(i)
		pqOth.add(Pair(a[i], i))
	}
	var minElem = 1e12.toLong()
	while(oth.isNotEmpty()){
		val p1 = getElem(oth, PQ)
		val p2 = getElem(oth, pqOth)
		val nxt =
			if(p1 == null){
				res += p2!!.first + minElem
                p2!!.second
			}
        	else if(p2 == null || p1.first < p2.first+minElem){
        	    if(p2 != null)
        	    	pqOth.add(p2)
				res += p1!!.first
        		p1.second
			}
			else{
			    PQ.add(p1)
				res += p2.first + minElem
				p2.second
			}
		minElem = minOf(minElem, a[nxt])
		oth.remove(nxt)
		for((b, d) in G[nxt]){
			PQ.add(Pair(d, b))
		}
	}
	println(res)
}