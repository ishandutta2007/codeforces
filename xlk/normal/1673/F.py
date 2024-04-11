n, k = map(int, input().split())
def gan(x):
	t = 1
	r = 0
	while x > 0:
		r += x % 2 * t
		t *= 4
		x //= 2
	return r
s = 0
for i in range(n):
	a = []
	for j in range(1, n):
		a.append(gan(j & -j))
	print(*a)
	s += sum(a)
for i in range(1, n):
	a = []
	for j in range(n):
		a.append(gan(i & -i) * 2)
	print(*a)
	s += sum(a)

x = 0
y = 0
for i in range(k):
	z = int(input())
	for j in range(10):
		if z >> j & 1:
			if j & 1:
				x ^= (1 << ((j // 2) + 1)) - 1
			else:
				y ^= (1 << ((j // 2) + 1)) - 1
	print(x + 1, y + 1, flush=True)