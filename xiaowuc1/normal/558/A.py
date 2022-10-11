n = int(raw_input())

l = []
for _ in xrange(n):
	a, b = (int(x) for x in raw_input().split())
	l.append((a, b))

l.append((-1000000000, 0))
l.append((1000000000, 0))

l = sorted(l)
firstPos = len(l)-1
while l[firstPos-1][0] > 0:
	firstPos -= 1
lastNeg = 0
while l[lastNeg+1][0] < 0:
	lastNeg += 1

ret = 0
while firstPos < len(l) and lastNeg >= 0:
	ret += l[firstPos][1]
	ret += l[lastNeg][1]
	firstPos += 1
	lastNeg -= 1

print ret