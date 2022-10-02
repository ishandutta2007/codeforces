n,k=[int(_) for _ in raw_input().split()]

if k == n:
	print -1
else:
	print n-k,
	for i in xrange(n-k-1):
		print i+1,
	for i in xrange(k):
		print n-(k-1)+i,
	print