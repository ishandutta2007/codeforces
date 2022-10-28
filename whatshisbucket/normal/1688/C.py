# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	par = {char: 0 for char in 'abcdefghijklmnopqrstuvwxyz'}
	for i in range(2 * n + 1):
		s = sys.stdin.readline().strip()
		for char in s:
			par[char] = 1 - par[char]
	for char in par:
		if par[char]:
			print(char)