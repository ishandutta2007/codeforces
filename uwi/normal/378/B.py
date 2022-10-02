n = input()
a = []
b = []

for i in xrange(n):
	x, y = map(int, raw_input().split())
	a.append(x)
	b.append(y)

p = 0
q = 0
while p+q < n:
	if p == n:
		q += 1
	elif q == n:
		p += 1
	elif a[p] < b[q]:
		p += 1
	else:
		q += 1

pmax = max(p, n/2)
qmax = max(q, n/2)

print "1"*pmax+"0"*(n-pmax)
print "1"*qmax+"0"*(n-qmax)