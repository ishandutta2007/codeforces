import sys
I=lambda:[*map(int, sys.stdin.readline().split())]

t,=I()
for _ in range(t):
	n, = I()
	a = I()

	best = 0
	for i in range(n):
		count = {}
		for j in range(n):
			if j != i:
				diffper = round((a[j]-a[i])/(j - i),6)
				if diffper in count:
					count[diffper] += 1
				else:
					count[diffper] = 1
		for guy in count:
			if count[guy] > best:
				best = count[guy]
	print(n - best - 1)