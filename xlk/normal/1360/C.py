t = input()
for tt in range(t):
	n = input()
	a = map(int, raw_input().split())
	c = sum(i % 2 for i in a)
	if c % 2 == 1:
		b = [i + 1 for i in a]
		if set(a) & set(b):
			print 'YES'
		else:
			print 'NO'
	else:
		print 'YES'