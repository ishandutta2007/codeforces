n, s = raw_input().split()
if s == '10':
	if n == '1':
		print -1
	else:
		print 10 ** (int(n) - 1)
else:
	print s * int(n)