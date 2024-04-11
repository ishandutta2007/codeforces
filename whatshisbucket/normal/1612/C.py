import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	k, x = map(int, inpu().split())
	if x >= k ** 2:
		print(2 * k - 1)
	else:
		if x <= k * (k + 1) // 2:
			approx = int((2 * x) ** 0.5) - 1
			while x > approx * (approx + 1) // 2:
				approx += 1
			print(approx)
		else:
			missing = k ** 2 - x
			approx = int((2 * missing) ** 0.5) - 1
			while missing >= (approx + 1) * (approx + 2) // 2:
				approx += 1
			print(2 * k - 1 - approx)