# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	if n % 2:
		print('NO')
		continue
	a.sort()
	sml = a[:n // 2]
	big = a[n // 2:]
	things = [0] * n
	for i in range(n // 2):
		things[2 * i] = big[i]
	used = [0] * (n // 2)
	for i in range(n // 2 - 1, -1, -1):
		if sml[i] < things[0]:
			things[-1] = sml[i]
			used[i] = 1
			break
	else:
		print('NO')
		continue
	curr = n // 2 - 1
	ind = n - 3
	bad = False
	while ind > 0:
		while used[curr]:
			curr -= 1
		things[ind] = sml[curr]
		used[curr] = 1
		if things[ind] >= things[ind - 1] or things[ind] >= things[ind + 1]:
			bad = True
			print('NO')
			break
		ind -= 2
		curr -= 1
	if not bad:
		print('YES')
		print(*things)