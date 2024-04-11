n = input()
a = map(int, raw_input().split())
def gcd(x, y):
	if y == 0:
		return x
	return gcd(y, x % y)
if a.count(1):
	print n - a.count(1)
else:
	z = n + 1
	for i in range(n):
		g = a[i]
		for j in range(n - i):
			g = gcd(g, a[i + j])
			if g == 1:
				z = min(z, j)
	if z == n + 1:
		print -1
	else:
		print z + n - 1