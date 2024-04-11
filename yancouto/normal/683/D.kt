fun main(args : Array<String>) {
	//var (a, x, y) = readLine()!!.split(' ').map(String::toInt)
	val q = readLine()!!.toInt()
	for(g in 1..q) {
		val (n, m, p) = readLine()!!.split(' ').map(String::toInt)
		var ok = false
		for(i in 1..n)
			if((p % i) == 0 && (p / i) <= m)
				ok = true
		if(ok) println("Yes")
		else println("No")
	}
}