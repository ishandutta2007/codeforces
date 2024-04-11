import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	l, r, a = I()
	big = r // a + r % a
	poss = r - r % a - 1
	if poss >= l and r % a < a - 1:
		print(poss // a + poss % a)
	else:
		print(big)