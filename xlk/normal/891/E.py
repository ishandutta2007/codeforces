n, k = map(int, raw_input().split())
p = 1000000007
f = [1]
for x in map(int, raw_input().split()):
	f.append(0)
	for i in range(len(f) - 1)[::-1]:
		f[i + 1] = (f[i + 1] + f[i] * x) % p
z = 0
t = 1
for i in range(n + 1)[::-1]:
	z = (z + f[i] * pow(-1, n - i, p) % p * t) % p
	t = t * (k - n + i) % p * pow(n, p - 2, p) % p
print (f[n] - z) % p