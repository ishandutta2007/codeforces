n, k = map(int, raw_input().split())
c = 1
z = 0
f = [1, 0, 1, 2, 9]
for i in range(k + 1):
	z = (z + f[i] * c)
	c = c * (n - i) / (i + 1)
print z