private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
	val T = readInt()
	for (t in 1..T){
		val (n, a, b) = readInts()
		val S = StringBuilder(n)
		for(i in 0..n-1){
			var x = i % a
			x = Math.min(x, b-1)
			val resChar : Char = 'a' + x
			S.append(resChar)
		}
		System.out.println(S)
	}
}