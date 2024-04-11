private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
	val t = readInt()
	for (i in 1..t){
		var n = readInt()
		val n2 = n
		var fact = 1
		var cnt = 0
		while( n > 0){
			if(n % 10 != 0){
				cnt++
			}
			fact *= 10
			n /= 10
		}
		println(cnt)
		fact = 1
		n = n2
		while( n > 0){
			if(n % 10 != 0){
				print(n%10*fact)
				print(" ")
			}
			fact *= 10
			n /= 10
		}
		println()
	}
}