n, k, d = map(int, raw_input().split())
def F(n, x):
	f = [1] + [0] * n
	for i in range(1, n + 1):
		f[i] = sum(f[max(i - x, 0) : i])
	return f[n]
print (F(n, k) - F(n, d - 1)) % (10 ** 9 + 7)