import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	big = max(a)
	ind = n - 1
	tot = 0
	seen = 0
	while a[ind] != big:
		if a[ind] > seen:
			seen = a[ind]
			tot += 1
		ind -= 1
	print(tot)