n = input()
a = map(int, raw_input().split())
f = [0]*5001
for v in a:
	f[v] += 1
lis = []
for i in xrange(5000, -1, -1):
	if len(lis) == 0:
		if f[i] >= 1:
			lis.append(i)
	else:
		if f[i] == 1:
			lis.append(i)
		elif f[i] >= 2:
			lis.append(i)
			lis.insert(0, i)

print len(lis)
print " ".join(map(str, lis))