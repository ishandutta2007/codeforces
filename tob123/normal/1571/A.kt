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
  val T = readInts().get(0)
  for(i in 0 until T){
      val s = readLn()
      println(s.fold(s[0]) {
          acc,c ->
          if(acc == '?' || (acc == '>' && c == '<') || (acc == '<' && c == '>')) '?'
          else if (acc == '<' || c == '<') '<'
          else if (acc == '>' || c == '>') '>'
          else c
          })
  }
}