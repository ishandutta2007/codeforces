l = sorted([int(x) for x in raw_input().split()])
ret = False
if l[0] == 1:
	ret = True
if l[1] == 2:
	ret = True
if l[2] == 3:
	ret = True
if l[0] == 2 and l[1] == 4 and l[2] == 4:
	ret = True
if l[0] == 2 and l[1] == 3 and l[2] == 3:
	ret = False
print "YES" if ret else "NO"