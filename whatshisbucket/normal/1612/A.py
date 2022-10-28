import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	x, y = map(int, inpu().split())
	if (x + y) % 2 != 0:
		print(-1,-1)
	else:
		if x % 2 == 0:
			print(x//2, y//2)
		else:
			print(x//2, y//2+1)