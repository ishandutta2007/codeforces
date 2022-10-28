import sys
inpu = sys.stdin.readline
prin = sys.stdout.write
m = 998244353
t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	d = {(0, -1): 1}
	for i in range(n + 1):
		d[(i + 1, i)] = 0
	for i in range(n):
		d[(i, i + 1)] = 0
	for guy in a:
		if guy > 0:
			d[(guy - 1, guy)] = (2 * d[(guy - 1, guy)] + d[(guy - 1, guy - 2)]) % m
		d[(guy + 1, guy)] = (2 * d[(guy + 1, guy)] + d[(guy, guy - 1)]) % m
		if guy < n - 1:
			d[(guy + 1, guy + 2)] = (2 * d[(guy + 1, guy + 2)]) % m
	tot = sum(d[guy] for guy in d)
	prin(str((tot - 1) % m) + '\n')