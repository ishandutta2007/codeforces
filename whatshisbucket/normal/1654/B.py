# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = input()
	last = {}
	for i in range(len(s)):
		last[s[i]] = i
	m = min(last[guy] for guy in last)
	print(s[m:])