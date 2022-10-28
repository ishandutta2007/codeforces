# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def process(a):
	if len(a) == 0:
		return (0, 0, 0)
	l = len(a)
	twos = 0
	sign = 1
	for guy in a:
		if guy < 0:
			sign = -sign
		if abs(guy) == 2:
			twos += 1
	if sign == 1:
		return (twos, 0, 0)
	start = 0
	stwos = 0
	for i in range(l):
		if abs(a[i]) == 2:
			stwos += 1
		if a[i] < 0:
			break
	opt1 = (twos - stwos, i + 1, 0)
	end = 0
	etwos = 0
	for i in range(l):
		if abs(a[-i - 1]) == 2:
			etwos += 1
		if a[-i - 1] < 0:
			break
	opt2 = (twos - etwos, 0, i + 1)
	return max(opt1, opt2)

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	zeroes = []
	for i in range(n):
		if a[i] == 0:
			zeroes.append(i)
	if len(zeroes) == 0:
		x, y, z = process(a)
		print(y, z)
		continue
	x, y, z = process(a[:zeroes[0]])
	best = (x, y, z + n - zeroes[0])
	for i in range(len(zeroes) - 1):
		x, y, z = process(a[zeroes[i] + 1: zeroes[i + 1]])
		best = max(best, (x, y + zeroes[i] + 1, z + n - zeroes[i + 1]))
	x, y, z = process(a[zeroes[-1] + 1:])
	best = max(best, (x, y + zeroes[-1] + 1, z))
	print(best[1], best[2])