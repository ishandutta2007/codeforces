import sys
import time
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	a, b, c = map(int, inpu().split())
	if (c + a - 2 * b) % 3 == 0:
		print(0)
	else:
		print(1)