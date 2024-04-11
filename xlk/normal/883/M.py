a, b = map(int, raw_input().split())
c, d = map(int, raw_input().split())
e = (abs(a - c) + abs(b - d) + 2) * 2
if a == c or b == d:
	e += 2
print e