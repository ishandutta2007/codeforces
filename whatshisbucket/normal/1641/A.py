import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, x = I()
	a = I()
	a.sort()
	count = {}
	for guy in a:
		if guy in count:
			count[guy] += 1
		else:
			count[guy] = 1

	for guy in a:
		if count[guy] > 0 and guy * x in count and count[guy * x] > 0:
			count[guy] -= 1
			count[guy * x] -= 1

	print(sum(count[guy] for guy in count))