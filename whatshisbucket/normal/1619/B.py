import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t,=I()
for _ in range(t):
	n, = I()
	sq = int(n**0.5+.00000000001)
	cb = int(n**(1/3)+.00000000001)
	six = int(n**(1/6)+.00000000001)
	print(sq+cb-six)