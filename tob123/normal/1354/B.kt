private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
	val t = readInt()
	for (T in 1..t){
		val s = readLn()
		val A = Array(s.length+1) {Array<Int>(8) {s.length+10}}
		A[0][0] = 0
		var bst = s.length+1
		for (i in 1..(s.length)){
			A[i][0] = 0
			val x = (s[i-1]-'0').toInt() - 1
			for(j in 0..7){
				A[i][j] = minOf(A[i][j], A[i-1][j]+1)
				if((j and (1 shl x)) > 0)
					A[i][j] = minOf(A[i][j], A[i-1][j xor (1 shl x)] + 1)
			}
			bst = minOf(bst, A[i][7])
		}
		println(if (bst > s.length) 0 else bst)
	}
}