# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	l, r = I()
	a = set(I())
	length = r - l + 1

	x = [i for i in range(l, r + 1)]
	ones = [0] * 17
	for guy in x:
		curr = guy
		for i in range(17):
			ones[i] += curr & 1
			curr >>= 1
	aones = [0] * 17
	for guy in a:
		curr = guy
		for i in range(17):
			aones[i] += curr & 1
			curr >>= 1
	out = 0
	for i in range(16, -1, -1):
		if ones[i] != aones[i]:
			out += 1 << i
		elif ones[i] == length // 2:
			useful = []
			auseful = []
			for guy in x:
				if guy >> (i + 1) == l >> (i + 1):
					useful.append(guy)
			for guy in a:
				if (guy ^ out) >> (i + 1) == l >> (i + 1):
					auseful.append(guy)
			os = 0
			aaa = 0
			for guy in useful:
				if guy >> i & 1:
					os += 1
			for guy in auseful:
				if guy >> i & 1:
					aaa += 1
			if os != aaa:
				out += 1 << i
	print(out)