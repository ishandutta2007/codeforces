private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var q = readInt()
	repeat(q){
		var (a,b) = readInts()
		var c = 0;
		if(a<b){
			c = a-1
		}else{
			c = b-1
		}
		println("${c} ${a-c} ${b-c}")
	}
}