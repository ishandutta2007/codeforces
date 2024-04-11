val A = listOf(4, 8, 15, 16, 23, 42)

fun main() {
	var n = readLine()!!.toInt()
	val a = readLine()!!.split(" ").map {it.toInt()}.map {A.indexOf(it)}
	val f = IntArray(5)

	var ans = 0
	for (i in a) {
		if (i > 0 && f[i - 1] == 0) {
			++ans
			continue
		}
		if (i > 0) {
			--f[i - 1]
		}
		if (i < 5) {
			++f[i]
		}
	}

	for (i in 0..4) {
		ans += f[i] * (i + 1)
	}

	println(ans)
}