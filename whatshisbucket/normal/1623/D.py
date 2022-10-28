I=lambda:[*map(int, input().split())]

t, = I()
for _ in range(t):
	n, m, rb, cb, rd, cd, p = I()
	if rd >= rb:
		row1 = rd - rb
		row2 = 2 * n - rd - rb
	else:
		row1 = 2 * n - rd - rb
		row2 = 2 * n - 2 + rd - rb
	if cd >= cb:
		col1 = cd - cb
		col2 = 2 * m - cd - cb
	else:
		col1 = 2 * m - cd - cb
		col2 = 2 * m - 2 + cd - cb
	times = []
	x = 2 * n - 2
	y = 2 * m - 2
	row1 %= x
	row2 %= x
	col1 %= y
	col2 %= y
	#print(row1, row2, col1, col2)
	g = x * y
	for i in range(g // x):
		times.append(row1 + x * i)
		times.append(row2 + x * i)
	for i in range(g // y):
		times.append(col1 + y * i)
		times.append(col2 + y * i)
	times = sorted(list(set(times)))
	#print(times)
	mod = 10 ** 9 + 7
	l = len(times)
	denom = (pow(100, l, mod) - pow(100 - p, l, mod)) % mod
	inv = pow(100, mod - 2, mod)
	num = 0
	power = pow(100, l - 1, mod)
	for i in range(l):
		num += (times[i] * p * power) % mod
		power = (power * (100 - p) * inv) % mod
	num += g * pow(100, l, mod)
	num -= g * denom
	num %= mod
	print(num * pow(denom, mod - 2, mod) % mod)