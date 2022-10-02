n, m = map(int, raw_input().split())
a = map(int, raw_input().split())
s = set()
ret = []
for i in reversed(xrange(n)):
	s.add(a[i])
	ret.append(len(s))
for i in xrange(m):
	print ret[n-input()]