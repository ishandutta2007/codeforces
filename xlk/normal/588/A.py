n = input()
p = 100
z = 0
for i in range(n):
	x, y = map(int, raw_input().split())
	p = min(p, y)
	z += x * p
print z