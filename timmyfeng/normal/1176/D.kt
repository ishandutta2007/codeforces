const val B = 2750131 + 1

fun main() {
	var n = readLine()!!.toInt()
	val b = readLine()!!.split(" ").map {it.toInt()}.sortedDescending()

	val sieve = IntArray(B)
	val primes = mutableListOf<Int>()

	for (i in 2 until B) {
		if (sieve[i] == 0) {
			primes.add(i)
			sieve[i] = i
		}

		for (j in primes) {
			if (i * j >= B) {
				break
			}
			sieve[i * j] = j
			if (i % j == 0) {
				break
			}
		}
	}

	val skip = IntArray(B)
	val a = mutableListOf<Int>()

	for (i in b) {
		when {
			skip[i] > 0 -> {
				--skip[i]
			}
			i == sieve[i] -> {
				val p = primes.binarySearch(i) + 1
				++skip[p]
				a.add(p)
			}
			else -> {
				++skip[i / sieve[i]]
				a.add(i)
			}
		}
	}

	for (i in a) {
		print("$i ")
	}
	println()
}