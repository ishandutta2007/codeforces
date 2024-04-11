private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
	val t = readInt()
	for (TT in 1..t){
		val (n, m) = readInts()
		var used = IntArray(n) {0}
		var A = Array<Triple<Int,Int,Int>>(m) {Triple(0,0,0)}
		for(i in 1..m){
			val (u, v, c) = readInts()
			A[i-1] = Triple(c, u, v)
		}
		A.sortBy({(c, x, y) -> -c})
		var pos = true
		for((c,x,y) in A){
			if(used[x-1]!=0 && used[x-1]!=c && used[y-1]!=0 && used[y-1]!=c){
				pos = false
				break
			}
			if(used[x-1]==0)
				used[x-1] = c
			if(used[y-1]==0)
				used[y-1] = c
		}
		if(pos){
			println("YES")
			for(x in used)
				print("$x ")
			println()
		}
		else{
			println("NO")
		}
	}
}