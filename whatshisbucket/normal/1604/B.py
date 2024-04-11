import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	inc = True
	for i in range(n-1):
		if a[i] >= a[i+1]:
			inc = False
	if inc and n % 2 == 1:
		print("NO")
	else:
		print("YES")