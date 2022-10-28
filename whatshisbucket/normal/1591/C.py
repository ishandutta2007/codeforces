import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n, k = map(int, inpu().split())
	x = list(map(int, inpu().split()))
	y = [guy for guy in x if guy < 0]
	x = [guy for guy in x if guy > 0]
	x.sort()
	y.sort(reverse = True)
	ind = len(x) - 1
	tot = 0
	while ind >= 0:
		tot += 2 * x[ind]
		ind -= k
	ind = len(y) - 1
	while ind >= 0:
		tot -= 2 * y[ind]
		ind -= k
	if len(y) == len(x) == 0:
		print(0)
		continue
	if len(y) == 0:
		tot -= x[-1]
	elif len(x) == 0:
		tot += y[-1]
	else:
		tot -= max(x[-1], -y[-1])
	print(tot)