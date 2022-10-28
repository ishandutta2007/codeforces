import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	s = input()
	if s == s[::-1] or k == 0:
		print(1)
	else:
		print(2)