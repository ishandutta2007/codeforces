# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	c = I()
	arr = []
	i = 0
	while len(arr) < n:
		#print(i, arr)
		if i >= len(arr):
			if c[i] == 0:
				arr.append(0)
			else:
				for j in range(c[i] - i):
					arr.append(1)
				arr.append(0)
		else:
			if arr[i] == 0:
				while len(arr) < i + c[i]:
					arr.append(1)
				arr.append(0)
			else:
				while len(arr) < c[i]:
					arr.append(1)
				arr.append(0)
		i += 1
	print(*arr[:n])