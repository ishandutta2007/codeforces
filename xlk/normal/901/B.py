f = [[1], [0, 1]]
n = input()
for i in range(1, n):
	a = [0] + f[-1]
	for j in range(i):
		a[j] += f[-2][j]
	f.append(a)
print n
for i in f[n]:
	print i % 2,
print
n -= 1
print n
for i in f[n]:
	print i % 2,
print