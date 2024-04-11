n = input()
x, y = 1, 0
for i in map(int, raw_input().split()):
	if i < 0:
		x, y = y, x
	x += 1
print x * y, n * (n + 1) / 2 - x * y