n,m,k = map(int, raw_input().split())
a = []
for i in xrange(n):
	a.append(map(int, raw_input().split()))

if k == 0:
	print m*(m-1)/2
	for i in xrange(m):
		for j in xrange(m-1, i, -1):
			print j, j+1
else:
	print m*(m-1)/2
	for i in xrange(m):
		for j in xrange(m-1, i, -1):
			print m-j+1, m-j