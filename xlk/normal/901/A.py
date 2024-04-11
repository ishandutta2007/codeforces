n = input()
a = map(int, raw_input().split())
s = l = 0
p = []
q = []
for i in a:
	for j in range(i):
		p.append(s)
		q.append(s - (j and l))
	s += i
	l = i - 1
if p == q:
	print 'perfect'
else:
	print 'ambiguous'
	for i in p:
		print i,
	print
	for i in q:
		print i,
	print