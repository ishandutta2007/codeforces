n = int(raw_input())
l = []
for i in range(n):
	c = raw_input()
	l.append(c)
l.sort(key = len)
ans = 1
for i in range(len(l)-1):
	if not l[i] in l[i+1]:
		ans = 0
if ans == 1:
	print "YES"
	for i in l:
		print i
else:
	print "NO"