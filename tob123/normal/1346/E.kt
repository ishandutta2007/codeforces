private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
	val t = 1
	val INF = 10000000
	for (TT in 1..t){
		val (n, m, k) = readInts()
		var pos = IntArray (n+1) {INF}
		pos[k] = 0
		for(i in 1..m){
			val (x,y) = readInts()
			var p1 = minOf(pos[x]+1, pos[y])
			var p2 = minOf(pos[y]+1, pos[x])
			pos[x] = p1
			pos[y] = p2
		}
		for(i in 1..n){
			print("${if (pos[i] == INF) -1 else pos[i]} ")
		}
		println()
	}
}