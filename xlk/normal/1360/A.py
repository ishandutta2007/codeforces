t = input()
for tt in range(t):
	a, b = map(int, raw_input().split())
	if a > b:
		a, b = b, a
	a *= 2
	print max(a, b) ** 2