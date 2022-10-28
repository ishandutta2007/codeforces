import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	a = I()
	b = I()
	c = sorted(zip(a, b))
	ind = 0
	while ind < n and c[ind][0] <= k:
		k += c[ind][1]
		ind += 1
	print(k)