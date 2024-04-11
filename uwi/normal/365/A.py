n,k = [int(_) for _ in raw_input().split()]
ct = 0
for i in xrange(n):
	b = 0
	for c in raw_input():
		b |= 1<<int(c)
	q = (1<<k+1)-1
	if (b&q)==q:
		ct += 1
print ct