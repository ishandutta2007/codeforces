private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

var a = IntArray(0)

fun solve(n : Int){
	if(n == 0)
		return
	else if(n == 1)
		a[n-1] = 1
	else if(n == 7){
		a[0] = 1
		a[1] = 3
		a[2] = 5
		a[3] = 2
		a[4] = 6
		a[5] = 4
		a[6] = 7
	}
	else if(n != 6){
		a[n-1] = n-1
		a[n-2] = n-3
		a[n-3] = n
		a[n-4] = n-2
		solve(n-4)
	}
	else{
		a[0] = 1
		a[1] = 3
		a[2] = 5
		a[3] = 2
		a[4] = 4
		a[5] = 6
	}
}

fun main(){
	val t = readInt()
	for (i in 1..t){
		val n = readInt()
		a = IntArray(n)
		if(n == 2 || n == 3)
			println(-1)
		else{
			solve(n)
			for(x in a)
				print("$x ")
			println()
		}
	}
}