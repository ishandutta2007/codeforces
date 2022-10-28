import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	a.sort()
	cred = 1
	redsum = a[-1]
	cblue = 2
	bluesum = a[0] + a[1]
	good = False
	while cred + cblue < n:
		if cred < cblue and redsum > bluesum:
			good = True
			break
		if cred >= cblue:
			bluesum += a[cblue]
			cblue += 1
		elif bluesum >= redsum:
			cred += 1
			redsum += a[-cred]
	if cred < cblue and redsum > bluesum:
		good = True
	if good:
		print("YES")
	else:
		print("NO")