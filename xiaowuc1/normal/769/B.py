n = int(raw_input())
l = [int(x) for x in raw_input().split()]

if l[0] == 0:
	print -1
	exit()

ret = []

q = [0]
done = [False] * n
done[0] = True
need = n-1
while q and need:
	curr = q.pop()
	while need and l[curr]:
		l[curr] -= 1
		need -= 1
		best = -1
		val = -1
		for i in xrange(len(l)):
			if not done[i] and l[i] > val:
				val = l[i]
				best = i
		ret.append((curr+1, best+1))
		q.append(best)
		done[best] = True

if need:
	print -1
	exit()
print len(ret)
for x in ret:
	print "{} {}".format(x[0], x[1])