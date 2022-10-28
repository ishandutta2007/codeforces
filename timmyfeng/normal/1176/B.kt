fun main() {
	var t = readLine()!!.toInt()
	while (t-- > 0) {
		val n = readLine()!!.toInt()
		val a = readLine()!!.split(" ").map {it.toInt()}
		val f = IntArray(3)
		for (i in a) {
			++f[i % 3]
		}
		if (f[1] < f[2]) {
			println(f[0] + f[1] + (f[2] - f[1]) / 3)
		} else {
			println(f[0] + f[2] + (f[1] - f[2]) / 3)
		}
	}
}