n = input()

a = [int(_) for _ in raw_input().split()]
b = []
if n <= 2:
	print n
else:
	ct = 0
	mx = 2
	for i in xrange(n-2):
		if a[i]+a[i+1] == a[i+2]:
			ct += 1
			mx = max(mx, ct+2)
		else:
			ct = 0
	print mx