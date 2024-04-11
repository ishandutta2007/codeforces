private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
	val t = readInt()
	for (i in 1..t){
		val n = readInt()
		val A = readLongs()
		val sm = A.sum()
		val res = (sm+n-1) / n
		System.out.println(res)
	}
}