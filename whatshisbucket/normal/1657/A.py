# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())
 
import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
 
t, = I()
for _ in range(t):
	x, y = I()
	if x == y == 0:
		print(0)
		continue
	z = x ** 2 + y ** 2
	#print(z)
	if int(z ** 0.5 + .000001) ** 2 == z:
		print(1)
	else:
		print(2)