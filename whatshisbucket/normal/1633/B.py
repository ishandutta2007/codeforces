import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = [*input()]
	a = s.count('0')
	b = s.count('1')
	if a == b:
		print(a - 1)
	else:
		print(min(a, b))