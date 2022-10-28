import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	a, b, x = map(int, inpu().split())
	if b > a:
		a, b = b, a
	done = False
	while b > 0:
		if (x >= b and x <= a and x % b == a % b) or x == a:
			done = True
			print("YES")
			break
		a, b = b, a % b
	if not done:
		print("NO")