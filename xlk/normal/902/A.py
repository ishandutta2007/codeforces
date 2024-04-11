n, m = map(int, raw_input().split())
b = 0
for i in range(n):
	s, t = map(int, raw_input().split())
	if s <= b:
		b = max(b, t)
print ['NO', 'YES'][b >= m]