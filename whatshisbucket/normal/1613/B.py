import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	a.sort()
	for i in range(1, n // 2 + 1):
		prin(str(a[i]) + ' ' + str(a[0]) + '\n')