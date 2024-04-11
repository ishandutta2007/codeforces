n, k = map(int, raw_input().split())

z = 10 ** 100
for i in map(int, raw_input().split()):
	if k % i == 0:
		z = min(z, k / i)
print z