fun main() {
	val t = readLine()!!.toInt()
	for (i in 1..t) {
		var n = readLine()!!.toLong()
		var ans = 0
		while (n % 5 == 0L) {
			n /= 5
			n *= 4
			++ans
		}
		while (n % 3 == 0L) {
			n /= 3
			n *= 2
			++ans
		}
		while (n % 2 == 0L) {
			n /= 2
			++ans
		}
		println(if (n == 1L) ans else -1)
	}
}