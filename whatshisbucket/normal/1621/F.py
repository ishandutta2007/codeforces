import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, a, b, c = I()
	s = input()
	start = int(s[0])
	curr = s[0]
	ind = 0
	blocks = []
	for i in range(1, n):
		if s[i] != curr:
			blocks.append(i - ind)
			curr = s[i]
			ind = i
	blocks.append(n - ind)
	l = len(blocks)
	zero = 0
	one = 0
	for i in range(l):
		if i % 2 == start:
			zero += blocks[i] - 1
		else:
			one += blocks[i] - 1
	if c > b:
		val = (a + b) * min(zero, one)
		if zero > one:
			print(val + a)
		elif one > zero:
			print(val + b)
		else:
			print(val)
	else:
		zeroes = [blocks[i] for i in range(l) if i % 2 == start and i > 0 and i < l - 1]
		zeroes.sort()
		extra = 0
		xxtra = 0
		if start == 0:
			extra += blocks[0] - 1
			xxtra += 1
		if (l - 1) % 2 == start:
			extra += blocks[-1] - 1
			xxtra += 1
		z1 = zeroes[:]
		extra1 = extra
		xxtra1 = xxtra

		val1 = 0
		ind = 0
		for i in range(one):
			while ind < len(zeroes) and zeroes[ind] == 1:
				ind += 1
			if ind < len(zeroes):
				zeroes[ind] -= 1
				val1 += a
			elif extra > 0:
				extra -= 1
				val1 += a
			elif xxtra > 0:
				xxtra -= 1
				val1 -= c
			else:
				break
			val1 += b
		val1 += (b - c) * zeroes.count(1)
		if (len(zeroes) > 0 and max(zeroes) > 1) or extra > 0:
			val1 += a

		val2 = 0
		ind = 0
		for i in range(one):
			val2 += b
			if i == one - 1:
				break
			while ind < len(zeroes) and z1[ind] == 1:
				ind += 1
			if ind < len(z1):
				z1[ind] -= 1
				val2 += a
			elif extra1 > 0:
				extra1 -= 1
				val2 += a
			elif xxtra1 > 0:
				xxtra1 -= 1
				val2 -= c
			else:
				break
		val2 += (b - c) * z1.count(1)
		print(max(val1, val2))