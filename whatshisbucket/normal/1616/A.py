import sys
I=lambda:[*map(int, sys.stdin.readline().split())]

t,=I()
for _ in range(t):
	n, = I()
	a = I()
	for i in range(n):
		a[i] = abs(a[i])
	count = {}
	for guy in a:
		if guy in count:
			count[guy] += 1
		else:
			count[guy] = 1
	tot = 0
	for guy in count:
		if guy != 0:
			tot += min(count[guy], 2)
		else:
			tot += 1
	print(tot)