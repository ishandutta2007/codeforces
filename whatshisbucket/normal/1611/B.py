t = int(input())
for _ in range(t):
	a, b = map(int, input().split())
	if b > 3 * a:
		print(a)
	elif a > 3 * b:
		print(b)
	else:
		print((a + b) // 4)