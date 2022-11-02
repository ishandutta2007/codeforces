private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
	val t = readInt()
	for (i in 1..t){
		val (a1,b1) = readInts()
		val (a2,b2) = readInts()
		if(a1 == a2 && b1 + b2 == a1
			|| a1 == b2 && b1 + a2 == a1
			|| b1 == a2 && a1+b2 == b1
			|| b1 == b2 && a1+a2 == b1)
			println("Yes")
		else
			println("No")
	}
}