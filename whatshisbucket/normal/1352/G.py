# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	if n < 4:
		print(-1)
	elif n == 4:
		print(*[3, 1, 4, 2])
	else:
		out = [guy for guy in range(n) if guy % 2 == 0]
		out.append(out[-1] - 3)
		if n % 2 == 0:
			out.append(out[-1] + 4)
			out.append(out[-1] - 2)
			if len(out) < n:
				out.append(out[-1] - 4)
		else:
			out.append(out[-1] + 2)
			if len(out) < n:
				out.append(out[-1] - 4)
		while len(out) < n:
			out.append(out[-1] - 2)
		print(*[guy + 1 for guy in out])