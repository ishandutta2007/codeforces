fun mdc(a : Long, b : Long) : Long {
	if(b == 0L) return a
	return mdc(b, a % b)
}

fun main(args : Array<String>) {
	//var (a, x, y) = readLine()!!.split(' ').map(String::toInt)
	val f = readLine()!!
	var a1 = 0L
	var b1 = 1L
	var a2 = 0L
	var b2 = 1L
	if('.' in f) {
		var st = 0
		for(j in 0..100)
			if(f[j] == '.') {
				st = j
				break
			}
		for(i in (st + 1)..100) {
			if(!f[i].isDigit()) break
			b1 = 10L * b1
			a1 = 10L * a1 + f[i].toLong() - '0'.toLong()
		}
	}
	var st = 0
	for(j in 1..100)
		if(f[j] == '(') {
			st = j
			break
		}
	for(i in (st + 1)..100) {
		if(!f[i].isDigit()) break
		b2 = 10L * b2
		a2 = 10L * a2 + f[i].toLong() - '0'.toLong()
	}
	b2--
	a1 = a1 * b2 + a2
	b1 = b1 * b2
	var m = mdc(a1, b1)
	println("${a1/m}/${b1/m}")
}