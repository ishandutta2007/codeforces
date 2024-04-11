a=raw_input()
b=raw_input()
if len(a)==len(b):
	c=sorted(a)
	d=sorted(b)
	for i in range(len(c)):
		if c[i]!=d[i]:
			print 'need tree'
			break
	else:print 'array'
elif len(a)<len(b):
	print 'need tree'
else:
	j=0
	for i in range(len(b)):
		while j<len(a) and a[j]!=b[i]:j+=1
		j+=1
	if j<=len(a):print 'automaton'
	else:
		a=sorted(a)
		b=sorted(b)
		j=0
		for i in range(len(b)):
			while j<len(a) and a[j]!=b[i]:j+=1
			j+=1
		if j<=len(a):print 'both'
		else:print 'need tree'