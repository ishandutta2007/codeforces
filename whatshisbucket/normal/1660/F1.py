# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	s = input()
	tot = 0
	for i in range(n):
		plus = 0
		minus = 0
		pairs = 0
		run = 0
		for j in range(i, n):
			if s[j] == '+':
				plus += 1
				run = 0
			else:
				minus += 1
				run += 1
				if run % 2 == 0:
					pairs += 1
			if minus >= plus and (minus - plus) % 3 == 0 and (minus - plus) // 3 <= pairs:
				tot += 1
	print(tot)