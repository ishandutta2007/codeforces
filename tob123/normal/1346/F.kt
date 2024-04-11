private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun calc(n:Int, m:Int, R:LongArray, C:LongArray, R2:LongArray, C2:LongArray) : Long{
	for(i in 1..n){
		R2[i] = R2[i-1]+R[i]
	}
	for(i in 1..n){
		R2[i] += R2[i-1]
	}
	val inf : Long = 4000000000.toLong() * 2000000000
	var rowB : Long = inf
	var sum : Long = 0
	var sum2 : Long = 0
	for(i in n downTo 1){
		rowB = minOf(rowB, sum2+R2[i-1])
		sum += R[i]
		sum2 += sum
	}
	for(i in 1..m){
		C2[i] = C2[i-1]+C[i]
	}
	for(i in 1..m){
		C2[i] += C2[i-1]
	}
	//println(rowB)
	var colB : Long = inf
	sum = 0
	sum2 = 0
	for(i in m downTo 1){
		colB = minOf(colB, sum2+C2[i-1])
		sum += C[i]
		sum2 += sum
	}
	//println(colB)
	return colB+rowB
}

fun main(){
	val (n, m, q) = readInts()
	var R = LongArray (n+2) {0}
	var C = LongArray (m+2) {0}
	var A = Array<LongArray>(n) {LongArray (0) {0}}
	for(i in 0..(n-1)){
		A[i] = readLongs().toTypedArray().toLongArray()
		for(j in 0..(m-1)){
			R[i+1] += A[i][j]
			C[j+1] += A[i][j]
		}
	}
	var R2 = LongArray(n+2) {0}
	var C2 = LongArray (m+2) {0}
	print(calc(n, m, R, C, R2, C2))
	for(Q in 1..q){
		var (x, y, z) = readInts()
		x--; y--
		R[x+1] -= A[x][y]
		C[y+1] -= A[x][y]
		A[x][y] = z.toLong()
		R[x+1] += z.toLong()
		C[y+1] += z.toLong()
		print(" ${calc(n, m, R, C, R2, C2)}")
	}
	println()
}