# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, q = I()
s = input()
ones = [0, 0]
zeroes = [0, 0]
for i in range(1, n):
	if s[i] == s[i - 1] == '0':
		zeroes.append(zeroes[-1] + 1)
	else:
		zeroes.append(zeroes[-1])
	if s[i] == s[i - 1] == '1':
		ones.append(ones[-1] + 1)
	else:
		ones.append(ones[-1])
for i in range(q):
	l, r = I()
	o = ones[r] - ones[l]
	z = zeroes[r] - zeroes[l]
	print(max(o, z) + 1)