import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n, h = map(int, inpu().split())
	a = list(map(int, inpu().split()))
	sml = 1
	big = 10 ** 18
	while big - sml > 0:
		mid = (big + sml) // 2
		dam = 0
		for i in range(n - 1):
			dam += min(mid, a[i + 1] - a[i])
		dam += mid
		if dam > h:
			big = mid
		elif dam < h:
			sml = mid + 1
		else:
			sml = big = mid
	print(sml)