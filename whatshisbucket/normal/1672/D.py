# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	b = I()
	prev = -1
	extra = {}
	curr = 0
	bad = False
	for i in range(n):
		want = b[i]
		if curr < n and a[curr] == want:
			curr += 1
		else:
			if want in extra and extra[want] > 0 and prev == want:
				extra[want] -= 1
			else:
				while True:
					if curr >= n or a[curr] == want:
						break
					if a[curr] in extra:
						extra[a[curr]] += 1
					else:
						extra[a[curr]] = 1
					curr += 1
				if curr == n:
					bad = True
					break
				else:
					curr += 1
		prev = b[i]
	if bad:
		print('NO')
	else:
		print('YES')