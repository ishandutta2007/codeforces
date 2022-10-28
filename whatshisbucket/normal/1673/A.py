# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = input()
	alpha = 'abcdefghijklmnopqrstuvwxyz'
	score = {alpha[i]: i + 1 for i in range(26)}
	if len(s) % 2 == 0:
		alice = sum(score[c] for c in s)
		bob = 0
	else:
		alice = sum(score[c] for c in s)
		bob = min(score[s[0]], score[s[-1]])
		alice -= bob
	if alice > bob:
		print('Alice', alice - bob)
	else:
		print('Bob', bob - alice)