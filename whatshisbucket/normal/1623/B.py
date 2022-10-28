import sys
I=lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	ranges = set()
	for i in range(n):
		ranges.add(tuple(I()))
	for a, b in ranges:
		if a == b:
			print(a, b, a)
		else:
			for i in range(a + 1, b):
				if (a, i - 1) in ranges and (i + 1, b) in ranges:
					print(a, b, i)
					break
			else:
				if (a + 1, b) in ranges:
					print(a, b, a)
				elif (a, b - 1) in ranges:
					print(a, b, b)