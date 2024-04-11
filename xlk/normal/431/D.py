m, k = map(int, raw_input().split())
k -= 1
def C(n, m):
	z = 1
	for i in range(m):
		z = z * (n - i) / (i + 1)
	return z
z = 1
for i in range(70)[::-1]:
	if C(i, k) < m:
		z += 2 ** i
		m -= C(i, k)
		k -= 1
print z