n, m, k = map(int, raw_input().split())
a = []
x, y = 0, 0
for i in range(n):
	a.append(map(int, raw_input().split()))
for i in zip(*a):
	u, v = 0, 0
	for j in range(n - k + 1):
		p, q = sum(i[j:j + k]), sum(i[:j])
		if p > u:
			u = p
			v = q
	x += u
	y += v
print x, y