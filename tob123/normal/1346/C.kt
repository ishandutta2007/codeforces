private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
	val t = readInt()
	for (T in 1..t){
		val (n,k, x, y) = readInts()
		var A = readLongs().toTypedArray().toLongArray()
		A.sortDescending() ;
		var sum = A.sum()
		var i = 0
		var res = y.toLong()
		var res2 : Long = 0
		for(z in A){
			if(z > k)
				res2 += x
		}
		while((sum+n-1)/n > k){
			sum -= A[i++]
			res += x
		}
		println(minOf(res, res2))
	}
}