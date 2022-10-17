t = input()
for tt in range(t):
	n, m = map(int, raw_input().split())
	a = []
	for i in range(n):
		a.append(int(raw_input(), 2))
	k = 2 ** m - n
	L = 0
	R = 2 ** m
	while L < R - 1:
		M = (L + R) / 2
		c = M
		for i in a:
			if i < M:
				c -= 1
		if c <= (k - 1) / 2:
			L = M
		else:
			R = M
	print bin(L + 2 ** m)[3:]