import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
prin = sys.stdout.write

t, = I()
for _ in range(t):
	l, r = I()
	best = 0
	size = r - l + 1
	i = 1
	while i < 3 * 10 ** 5:
		tot = i * (size // (2 * i))
		a = (l - 1) % (2 * i)
		b = r % (2 * i)
		#print(i, a, b, tot)
		if b > a:
			tot += max(0, b - max(i - 1, a))
		elif b < a:
			tot += min(i, 2 * i - a - 1)
			tot += max(0, b - i)
		if tot > best:
			best = tot
			#print(i, tot)
		i *= 2
	print(size - best)