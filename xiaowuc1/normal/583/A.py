n = int(raw_input())
a = set()
b = set()
ret = []
for _ in xrange(n*n):
	x, y = (int(z) for z in raw_input().split())
	if x in a or y in b:
		continue
	ret.append(str(_+1))
	a.add(x)
	b.add(y)
print " ".join(ret)