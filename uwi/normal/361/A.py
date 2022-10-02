n,k=[int(_) for _ in raw_input().split()]
for i in xrange(n):
	for j in xrange(n):
		if i == j:
			print k,
		else:
			print 0,
	print