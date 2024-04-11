import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n, k = map(int,inpu().split())
	l = len(bin(k))-3
	count = 2**(l+1)
	steps = l+1
	if n <= count:
		if n == 1:
			print(0)
		else:
			print(len(bin(n-1))-2)
	else:
		mod = (n-count) % k
		needed = (n-count) // k
		if mod > 0:
			needed += 1
		print(steps + needed)