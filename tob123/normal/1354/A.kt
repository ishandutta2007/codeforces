private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toLong() }

fun main(){
	val t = readInt()
	for (i in 1..t){
		var (a,b,c,d) = readInts()
		if (b < a){
			a -= b
			if(d >= c){
				println(-1)
			}
			else{
				println(b + ((a+c-d-1)/(c-d))*c)
			}
		}
		else{
			println(b)
		}
	}
}