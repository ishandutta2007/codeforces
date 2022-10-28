import sys
inpu = sys.stdin.readline

t = int(inpu())
for _ in range(t):
	n, l, r, k = map(int, inpu().split())
	a = list(map(int, inpu().split()))
	a.sort()
	left = k
	bought = 0
	for guy in a:
		if guy >= l and guy <= r and guy <= left:
			left -= guy
			bought += 1
	print(bought)