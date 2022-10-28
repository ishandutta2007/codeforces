import sys
inpu=sys.stdin.readline
prin=sys.stdout.write
I=lambda:[*map(int,inpu().split())]

t = I()[0]
for _ in range(t):
	n = I()[0]
	a = sorted(I())
	count = 0
	covered = [0] * (n + 1)
	sml = 1
	bad = False
	for i in range(n):
		if a[i] <= n and covered[a[i]] == 0:
			count += 1
			covered[a[i]] = 1
			if sml == a[i]:
				while sml <= n and covered[sml] == 1:
					sml += 1
		elif sml < a[i] / 2:
			covered[sml] = 1
			while sml <= n and covered[sml] == 1:
				sml += 1
		else:
			bad = True
	if bad:
		print(-1)
	else:
		print(n - count)