n, l = map(int, input().split())
c = list(map(int, input().split()))
for i in range(1, n):
	c[i] = min(c[i], c[i - 1] * 2)
while len(c) < 32:
	c.append(c[-1] * 2)
z = 0
for i in range(32):
	if l >> i & 1:
		z += c[i]
	else:
		z = min(z, c[i])
print(z)