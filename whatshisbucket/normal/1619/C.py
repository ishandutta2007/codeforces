import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t,=I()
for _ in range(t):
	a, s = I()
	b = 0
	i = 0
	bad = False
	while s > 0:
		if a % 10 <= s % 10:
			b += (10 ** i) * (s % 10 - a % 10)
			a //= 10
			s //= 10
			i += 1
		else:
			if s % 100 >= 20 or s % 100 < 10:
				bad = True
			b += (10 ** i) * (s % 10 - a % 10 + 10)
			a //= 10
			s //= 100
			i += 1
	if bad or a > 0:
		print(-1)
	else:
		print(b)