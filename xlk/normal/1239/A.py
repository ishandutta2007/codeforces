mod = 1000000007
f = [2] * 100001
for i in range(2, 100001):
	f[i] = (f[i-1] + f[i-2]) % mod
n, m = map(int, raw_input().split())
print (f[n]+f[m]-2) % mod