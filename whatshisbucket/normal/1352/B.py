# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	if k % 2 == 0:
		if n % 2 == 1:
			print("NO")
		else:
			n -= k - 1
			out = [1] * (k - 1)
			if n <= 0:
				print("NO")
			else:
				print("YES")
				out.append(n)
				print(*out)
	else:
		if n % 2 == 1:
			n -= k - 1
			out = [1] * (k - 1)
			if n <= 0:
				print("NO")
			else:
				print("YES")
				out.append(n)
				print(*out)
		else:
			n -= 2 * (k - 1)
			out = [2] * (k - 1)
			if n <= 0:
				print("NO")
			else:
				print("YES")
				out.append(n)
				print(*out)