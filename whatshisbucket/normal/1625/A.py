import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, l = I()
	x = I()
	y = []
	for i in range(l):
		ones = 0
		zeroes = 0
		for guy in x:
			if guy >> i & 1:
				ones += 1
			else:
				zeroes += 1
		if ones > zeroes:
			y.append(1)
		else:
			y.append(0)
	out = 0
	for i in range(l):
		out += y[i] << i
	print(out)