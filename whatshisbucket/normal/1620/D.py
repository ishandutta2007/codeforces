import sys
inpu=sys.stdin.readline
prin=sys.stdout.write
I=lambda:[*map(int,inpu().split())]

t = I()[0]
for _ in range(t):
	n, = I()
	a = I()
	m = max(a)
	x = m % 3
	if x == 0:
		bad = False
		for guy in a:
			if guy % 3 != 0:
				bad = True
				break
		if bad:
			print(m // 3 + 1)
		else:
			print(m // 3)
	elif x == 1:
		two = False
		one = False
		for guy in a:
			if guy % 3 == 2:
				two = True
			elif guy == 1 or guy == m - 1:
				one = True
		if two and one:
			print(m // 3 + 2)
		else:
			print(m // 3 + 1)
	else:
		one = False
		for guy in a:
			if guy % 3 == 1:
				one = True
				break
		if one:
			print(m // 3 + 2)
		else:
			print(m // 3 + 1)