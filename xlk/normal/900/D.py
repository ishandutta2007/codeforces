p = 1000000007
x, y = map(int, raw_input().split())
if y % x:
	print 0
else:
	y /= x
	d = set([])
	i = 1
	while i * i <= y:
		if y % i == 0:
			d.add(i)
			d.add(y / i)
		i += 1
	d = sorted(list(d))
	f = d[::]
	for i in range(len(d)):
		f[i] = pow(2, d[i] - 1, p)
		for j in range(i):
			if d[i] % d[j] == 0:
				f[i] -= f[j]
	print f[-1] % p