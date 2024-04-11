# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	s = input()
	degrees = [*map(int, [*s])]
	for i in range(n):
		if degrees[i] == 0:
			degrees[i] = 2
	x = sum(degrees)
	needed = 2 * n - 2
	degrees[0] += needed - x
	if (needed - x) % 2 == 1 or needed - x < 0:
		print('NO')
		continue
	if n == 2 and degrees == [1, 1]:
		print('YES')
		print(1, 2)
		continue
	if degrees[0] == 1:
		x = degrees.index(2)
		degrees = degrees[x:] + degrees[:x]
		shift = x
	else:
		shift = 0
	ones = degrees.count(1)
	print('YES')
	curr = False
	for i in range(1, n):
		if not curr:
			if ones > 1 or degrees[i] != 1:
				print(shift + 1, (shift + i) % n + 1)
				curr = True
			else:
				print(shift + 1, (shift - 1) % n + 1)
				for j in range(i + 1, n):
					print((shift + j - 1) % n + 1, (shift + j) % n + 1)
				break
			if degrees[i] == 1:
				ones -= 1
				curr = False
		elif degrees[i] == 2:
			print((shift + i) % n + 1, (shift + i - 1) % n + 1)
		else:
			curr = False
			ones -= 1
			if ones == 0:
				print((shift + i - 1) % n + 1, (shift - 1) % n + 1)
				for j in range(i + 1, n):
					print((shift + j - 1) % n + 1, (shift + j) % n + 1)
				break
			else:
				print((shift + i - 1) % n + 1, (shift + i) % n + 1)