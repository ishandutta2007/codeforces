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
	val inf = 1e7.toInt()
	val T = readInt()
	for(t in 0 until T){
		val n = readInt()
		val s = readLn().toCharArray()
		val a = readLn().split("").map { it=="1" }.drop(1).toMutableList()
		a.add(false); a.add(false); a.add(false)
		assert(a.size == n)
		val cost = Array(n+1) {IntArray(16) {0} }
		for(i in 0 until n){
			for(j in 0 until 16) {
				cost[i + 1][j] = minOf(cost[i][j shr 1], cost[i][(j shr 1) + 8])
			}
			val off = if(s[i] == ')') 0 else 8
			for(j in 0 until 8){
				cost[i+1][off+j]++
			}
			if(a[i]){
				for(j in 0 until 16){
					if(j != 3 && j != 5)
						cost[i+1][j] = inf
				}
			}
			/*
			println("$i: ${a[i]}")
			printColl(cost[i+1].toCollection(ArrayList<Int>()))
			 */
		}
		var res = inf
		for(i in 0 until 16)
			res = minOf(res, cost[n][i])
		if(res >= inf)
			println(-1)
		else
			println(res)
		/*
		val cur = mutableListOf<Int>()
		val fix = BooleanArray(n) {false}
		var cnt = 0
		for(i in a.indices){
			if(a[i] == '1')
				cur.add(i)
		}
		var imp = false
		for(x in cur.indices){
			if(s[x] == ')' && fix[x]) {
				imp = true
				break
			}
			if(s[x] == ')') cnt++
			if(s[x+3] == '(') cnt++
			s[x] = '('; s[x+3] = ')'
		}
		for(x in cur.indices){
			if(!fix[x+1] && !fix[x+2]){

			}
		}
		if(imp){
			println(-1)
			continue
		}
		 */
	}
}