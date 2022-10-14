a = raw_input()
if a != a[::-1]:
	print len(a)
else:
	if len(list(set(list(a)))) == 1:
		print 0
	else:
		print len(a)-1