n, m = map(int, raw_input().split())
z = 1e100

for i in range(n):
	x, y = map(float, raw_input().split())
	z = min(z, x / y * m)
print z