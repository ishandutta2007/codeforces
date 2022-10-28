# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def remove(n, counts):
	if n in counts and counts[n] > 0:
		#print(n)
		counts[n] -= 1
		return True
	if n == 1:
		return False
	l = n // 2
	x = remove(l, counts)
	if not x:
		return False
	y = remove(n - l, counts)
	if not y:
		return False
	return True

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	s = sum(a)
	counts = {}
	for guy in a:
		if guy in counts:
			counts[guy] += 1
		else:
			counts[guy] = 1
	ans = remove(s, counts)
	if ans:
		print('Yes')
	else:
		print('NO')