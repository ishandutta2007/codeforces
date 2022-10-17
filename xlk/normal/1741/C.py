t = int(input())
for tt in range(t):
	n = int(input())
	a = [0] + list(map(int, input().split()))
	for i in range(n):
		a[i + 1] += a[i]
	s = {}
	for i in range(n + 1):
		s[a[i]] = i
	z = n
	for i in range(1, n + 1):
		if a[n] % i == 0:
			d = a[n] // i
			l = 0
			for j in range(1, i + 1):
				if j * d not in s:
					break
				l = max(l, s[j * d] - s[(j - 1) * d])
			else:
				z = min(z, l)
	print(z)