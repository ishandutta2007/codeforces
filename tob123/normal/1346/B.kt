private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
	val t = readInt()
	for (i in 1..t){
		val (n, k1, k2) = readInts()
		val s = readLn()
		var cnt = 0
		var sum : Long = 0
		val x1 = minOf(k2, k1)
		val x2 = minOf(k1, k2-x1)
		for (c in s){
			if(c == '0'){
				sum += (cnt+1)/2*x1 + cnt/2*x2
				cnt = 0
			}
			else{
				cnt++
			}
		}
		sum += (cnt+1)/2*x1 + cnt/2*x2
		println(sum)
	}
}