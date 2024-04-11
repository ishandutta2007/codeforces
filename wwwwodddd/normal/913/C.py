n, l = map(int, raw_input().split())
c = map(int, raw_input().split())

for i in range(100):
	for i in range(1, n):
		c[i] = min(c[i], 2 * c[i - 1])

	for i in range(1, n)[::-1]:
		c[i - 1] = min(c[i - 1], c[i])

t = c[n - 1] * (l / (2 ** (n - 1)))
l %= 2 ** (n - 1)
z = 10 ** 20
for i in range(n)[::-1]:
	z = min(z, t + (l + 2 ** i - 1) / (2 ** i) * c[i])
	t += l / (2 ** i) * c[i]
	l %= 2 ** i
print z