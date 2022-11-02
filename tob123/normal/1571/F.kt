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
	var (n, m) = readInts()
	val K = IntArray(n)
	val T = IntArray(n)
	val res = mutableListOf<Pair<Int,Int>>()
	for(i in 0 until n){
		val (k, t) = readInts()
		K[i] = k; T[i] = t
		if(t == 1){
			m -= k
			res.add(Pair(i, m))
		}
	}
	if(m < 0){
		println(-1)
		return
	}
	val dp = IntArray(m+1) {-1}
	dp[0] = 0
	var sum = 0
	for(i in 0 until n){
		if(T[i] == 1) continue
		sum += K[i]
		for(j in dp.size-1 downTo K[i]){
			if(dp[j] == -1 && dp[j-K[i]] != -1){
				dp[j] = i
			}
		}
	}
	//printColl(dp.toCollection(ArrayList<Int>()))
	val hf = (m+1)/2
	var bst = 0
	for(i in 0 .. hf)
		if(dp[i] != -1)
			bst = i
	if(sum - bst > m/2){
		println(-1)
		return
	}
	val ind1 = mutableSetOf<Int>()
	var cur = bst
	while(cur > 0){
		ind1.add(dp[cur])
		cur -= K[dp[cur]]
	}
	val ind2 = mutableSetOf<Int>()
	for(i in 0 until n){
		if(T[i] != 1 && !ind1.contains(i))
			ind2.add(i)
	}
	for((st,coll) in listOf(Pair(0,ind1), Pair(1,ind2))){
		var cur = st
		//println(coll.joinToString(" ") {it.toString()})
		for(x in coll){
			res.add(Pair(x, cur))
			cur += 2*K[x]
		}
	}
	res.sortBy { it.first }
	println(res.joinToString(" ") { it.second.inc().toString() })
}