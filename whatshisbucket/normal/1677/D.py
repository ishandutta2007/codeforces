# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

M = 998244353
facs = [1]
for i in range(1000000):
	facs.append(facs[-1] * (i + 1) % M)

t, = I()
for _ in range(t):
	n, k = I()
	p = I()
	bad = False
	for i in range(n):
		if p[i] > i:
			bad = True
		if i >= n - k and p[i] > 0:
			bad = True
	if bad:
		print(0)
		continue
	inv = pow(k + 1, M - 2, M)
	stuff = [facs[k] * pow(k + 1, n - k, M) % M]
	for i in range(n):
		stuff.append(stuff[-1] * inv % M)
	#print(stuff)
	big = 0
	for guy in p:
		if guy > 0:
			big += 1

	tot = stuff[big]
	#print(tot)
	for i in range(n - k):
		if p[i] == -1:
			poss = i
			tot = (tot + poss * tot * inv) % M
	print(tot)