n, k = map(int, raw_input().split())
k = 240 - k
k /= 5
z = 0
for i in range(1, n + 1):
	if k >= i:
		k -= i
		z += 1
print z