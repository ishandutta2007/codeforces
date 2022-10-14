private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var q = readInt()
	var l2 = -1
	var l1 = -1
	var ans = 0
	var ali = readInts()
	var id = 0
	var c = 0
	repeat(q){
		c = ali[id]
		//println("$l2 $l1 $c")
		if(l1>c && l2>c){
			ans = ans+1
		}
		if(c>l2){
			l1 = l2
			l2 = c
		}else{
			if(c>l1){
				l1 = c
			}
		}
		id = id+1
	}
	println("$ans")
}