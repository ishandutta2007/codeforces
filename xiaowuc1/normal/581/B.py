n = int(raw_input())
l = [int(x) for x in raw_input().split()]
last = 0
ret = []
for i in xrange(n):
	ret.append(str(max(0, last+1-l[n-1-i])))
	last = max(last, l[n-1-i])
print " ".join(ret[::-1])