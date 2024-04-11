t = int(input())
for tt in range(t):
	a, b, c = map(int, input().split())
	z = c
	y = b
	x = a + c * y
	print(x, y, z)