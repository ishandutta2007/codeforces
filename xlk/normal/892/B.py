input()
z, x = 0, 0
for i in map(int, raw_input().split())[::-1]:
	if x == 0:
		z += 1
	x = max(x - 1, i)
print z