n, x = map(int, raw_input().split())
z = 0
for i in range(1, n + 1):
	if x % i == 0 and x / i <= n:
		z += 1
print z