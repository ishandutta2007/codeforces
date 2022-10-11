ret = 0
n, m = (int(x) for x in raw_input().split())
for _ in xrange(n):
	l = [int(x) for x in raw_input().split()]
	for __ in xrange(m):
		ret += min(1, l[2*__] + l[2*__+1])
print ret