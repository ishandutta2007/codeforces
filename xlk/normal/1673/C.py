n = 40000
p = 1000000007
f = [0 for i in range(n + 1)]
f[0] = 1
for i in range(1, n + 1):
	if str(i) == str(i)[::-1]:
		for j in range(i, n + 1):
			f[j] = (f[j] + f[j - i]) % p
for t in range(int(input())):
	print(f[int(input())])