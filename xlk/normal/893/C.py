R = lambda:map(int, raw_input().split())
n, m = R()
c = [0] + R()
f = range(n + 1)
def F(x):
	while f[x] != x:
		f[x] = f[f[x]]
		x = f[x]
	return x
for i in range(m):
	x, y = map(F, R())
	if c[x] > c[y]:
		f[x] = y
	else:
		f[y] = x
print sum(c[i] for i in range(1, n + 1) if f[i] == i)