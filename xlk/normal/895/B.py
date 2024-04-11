n, x, k = map(int, raw_input().split())
a = {}
u = {}
for i in map(int, raw_input().split()):
	a[i] = a.get(i, 0) + 1
z = 0
for i, j in sorted(a.items()):
	u[-i / x] = u.get(-i / x, 0) + j
	z += u.get(k - i / x - 1, 0) * j
print z