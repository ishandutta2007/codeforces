# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, m = I()
t = I()
bad = []
for guy in t:
	if m < 2 * guy + 1:
		print(-1)
		exit()
	elif m < 3 * guy:
		bad.append(guy)

out = []
counts = {}
for guy in t:
	if guy in counts:
		counts[guy] += 1
	else:
		counts[guy] = 1

for guy in bad:
	counts[guy] -= 1
	biggest = 0
	for boi in counts:
		if counts[boi] > 0 and guy % boi == 0 and boi + 2 * guy <= m:
			biggest = boi
	if biggest == 0:
		print(-1)
		exit()
	else:
		counts[biggest] -= 1
		out.append((guy + biggest, 2 * guy + biggest))

for guy in counts:
	for i in range(counts[guy]):
		out.append((2 * guy, 3 * guy))
print(len(out))
for guy in out:
	print(*guy)