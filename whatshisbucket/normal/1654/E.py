# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def main():
	n, = I()
	a = I()
	m = 100000
	rm = 401


	best = 0
	f = [0] * (m * (rm + 1))
	for i in range(-rm, rm + 1):
		for j in range(n):
			offset = a[j] - i * j
			f[offset] += 1
			best = max(best, f[offset])
		for j in range(n):
			offset = a[j] - i * j
			f[offset] = 0

	to = [[] for i in range(n)]
	for i in range(n):
		for j in range(i + 1, min(n, i + m // rm + 1)):
			if (a[j] - a[i]) % (j - i) == 0:
				diff = (a[j] - a[i]) // (j - i)
				if abs(diff) > rm:
					to[j].append((i, diff))

	#print(to)
	dp = {}
	for j in range(n):
		for i, x in to[j]:
			if (i, x) in dp:
				if (j, x) in dp:
					dp[(j, x)] = max(dp[(j, x)], dp[(i, x)] + 1)
				else:
					dp[(j, x)] = dp[(i, x)] + 1
			else:
				if (j, x) not in dp:
					dp[(j, x)] = 1
	if dp:
		#print(dp)
		best = max(best, max(dp.values()) + 1)
	print(n - best)

main()