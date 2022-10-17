x, y = map(int, raw_input().split())
z = 0
while y > 0:
	z += x / y
	x, y = y, x % y
print z