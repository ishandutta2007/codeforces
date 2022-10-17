n, x = map(int, raw_input().split())
p = 10 ** 9 + 7
a = [0] * 101
for i in map(int, raw_input().split()):
	a[i - 1] += 1

for i in range(1, 101)[::-1]:
	a[i] -= a[i - 1]
a[0] += 1

def F(n):
	if n == 0:
		return [1] + [0] * 100
	elif n % 2 == 1:
		b = F(n - 1)
		c = [0] + b
		for j in range(101):
			c[101 - j - 1] += c[101] * a[j]
			c[101 - j - 1] %= p
		return c[:101]
	else:
		b = F(n / 2)
		c = [0] * 202
		for i in range(101):
			for j in range(101):
				c[i + j] += b[i] * b[j]
				c[i + j] %= p
		for i in range(101, 202)[::-1]:
			for j in range(101):
				c[i - j - 1] += c[i] * a[j]
				c[i - j - 1] %= p
			c[i] = 0
		return c[:101]
print F(x + 100)[-1]