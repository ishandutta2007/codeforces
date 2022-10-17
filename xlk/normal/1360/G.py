t = input()
for tt in range(t):
	n, m, a, b = map(int, raw_input().split())
	if n * a == m * b:
		print 'YES'
		for i in range(n):
			s = ['0' for j in range(m)]
			for j in range(a):
				s[(i * a + j) % m] = '1'
			print ''.join(s)
	else:
		print 'NO'