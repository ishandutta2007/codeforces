import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = input()
	if s.index('r') < s.index('R') and s.index('b') < s.index('B') and s.index('g') < s.index('G'):
		print("YES")
	else:
		print("NO")