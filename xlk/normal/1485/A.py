t = int(input())
def F(a, b):
	r = 0
	while b < 2:
		b += 1
		r += 1
	while a > 0:
		a //= b
		r += 1
	return r
for tt in range(t):
	a, b = map(int, input().split())
	print(min(i + F(a, b + i) for i in range(100)))