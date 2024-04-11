import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	k = I()
	h = I()
	start = k[-1] - h[-1] + 1
	end = k[-1]
	tot = 0
	for i in range(n - 2, -1, -1):
		if k[i] >= start:
			start = min(start, k[i] - h[i] + 1)
		else:
			tot += (end - start + 1) * (end - start + 2) // 2
			start = k[i] - h[i] + 1
			end = k[i]

	tot += (end - start + 1) * (end - start + 2) // 2
	print(tot)