n = int(raw_input())
l = [int(x) for x in raw_input().split()]
ret = 360
for i in xrange(n):
	for j in xrange(i+1):
		s = sum(l[j:i+1])
		ret = min(ret, abs(360 - 2 * s))
print ret