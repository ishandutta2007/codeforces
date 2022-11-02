import java.util.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun printArray(a : IntArray){
	for(x in a)
		print("$x ")
	println()
}
private fun printArray(a : LongArray){
	for(x in a)
		print("$x ")
	println()
}
private fun <T>printArray(a : Array<T>){
	for(x in a)
		print("$x ")
	println()
}
private fun <T>printColl(a : Collection<T>){
	for(x in a)
		print("$x ")
	println()
}

fun main(){
	val T = 1
	for (t in 1..T){
		var (n, m, d) = readInts()
		val cc = readInts()
		val C = cc.toIntArray()
		var sum = C.sum()
        if((m+1)*(d-1) >= n-sum){
			println("YES")
            var gap = n - sum
			var ind = 0
			var res = IntArray(n)
			for(ci in 0 until m){
				val jmp = Math.min(gap, d-1)
				gap -= jmp
				ind += jmp
				for(j in ind until ind+C[ci]){
					res[j] = ci+1
				}
				ind += C[ci]
			}
			printArray(res)
		}
		else{
			println("NO\n")
		}
	}
}