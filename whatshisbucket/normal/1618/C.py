import sys
inpu = sys.stdin.readline
prin = sys.stdout.write
import math

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	even = a[0]
	for i in range(2, n, 2):
		even = math.gcd(even, a[i])
	odd = a[1]
	for i in range(3, n, 2):
		odd = math.gcd(odd, a[i])
	bad = False
	for i in range(1, n, 2):
		if a[i] % even == 0:
			bad = True
	if not bad:
		print(even)
		continue
	bad = False
	for i in range(0, n, 2):
		if a[i] % odd == 0:
			bad = True
	if not bad:
		print(odd)
		continue
	print(0)