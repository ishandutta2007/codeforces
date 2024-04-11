# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())
 
import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
 
t, = I()
for _ in range(t):
	n, B, x, y = I()
	a = [0]
	for i in range(n):
		if a[-1] + x <= B:
			a.append(a[-1] + x)
		else:
			a.append(a[-1] - y)
	print(sum(a))