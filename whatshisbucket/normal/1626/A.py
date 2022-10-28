import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = [*input()]
	print(''.join(sorted(s)))