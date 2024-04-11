private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
	val t = readInt()
	for (i in 1..t){
		val (n, k) = readInts()
		val n1 = n/(1+k*(1+k*(1+k)))
		val n2 = k*n1
		val n3 = k*n2
		val n4 = k*n3
		println("$n1 $n2 $n3 $n4")
	}
}