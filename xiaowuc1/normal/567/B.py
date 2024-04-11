n = int(raw_input())
capacity = 0
inside = 0
curr = set()
maxInsert = 0
records = []
alreadyInside = set()
for _ in xrange(n):
	l = [x for x in raw_input().split()]
	records.append(l)
	if l[0] == '+':
		curr.add(l[1])
	elif l[1] not in curr:
		alreadyInside.add(l[1])
	else:
		curr.remove(l[1])

curr = set()
for x in alreadyInside:
	curr.add(x)

ret = len(curr)
for l in records:
	if l[0] == '+':
		curr.add(l[1])
		ret = max(ret, len(curr))
	else:
		curr.remove(l[1])

print ret