import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	b = list(map(int, inpu().split()))
	tot = sum(b)
	if tot % ((n*(n+1))//2) != 0:
		print('NO')
		continue
	suma = tot // ((n*(n+1))//2)
	a = [0] * n
	bad = False
	for i in range(n - 1):
		thing = suma + b[i] - b[i + 1]
		if thing % n != 0:
			bad = True
		a[i + 1] = thing // n
	thing = suma + b[-1] - b[0]
	if thing % n != 0:
		bad = True
	a[0] = thing // n
	if bad or min(a) < 1:
		print('NO')
	else:
		print('YES')
		print(' '.join(str(guy) for guy in a))