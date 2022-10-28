# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())
 
import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
 
n, = I()
a = I()
 
best = float('inf')
for i in range(n):
	tot = 0
	curr = 0
	for j in range(i + 1, n):
		x = curr // a[j] + 1
		tot += x
		curr = x * a[j]
	curr = 0
	for j in range(i - 1, -1, -1):
		x = curr // a[j] + 1
		tot += x
		curr = x * a[j]
	best = min(tot, best)
print(best)