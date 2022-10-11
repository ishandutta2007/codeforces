n = int(raw_input())
l = [int(x) for x in raw_input().split()]
indices = [i for i in xrange(n) if l[i]]
ret = 0
last = -1000
for x in indices:
	if x == last+1 or x == last+2:
		ret += x - last
	else:
		ret += 1
	last = x
print ret