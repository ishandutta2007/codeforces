import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	b = I()
	x = min([abs(b[0] - a[i]) for i in range(n)])
	y = min([abs(b[-1] - a[i]) for i in range(n)])
	z = min([abs(a[0] - b[i]) for i in range(n)])
	w = min([abs(a[-1] - b[i]) for i in range(n)])
	poss = min(x + y + z + w, abs(b[0] - a[0]) + abs(b[-1] - a[-1]), abs(b[-1] - a[0]) + abs(b[0] - a[-1]), abs(b[0] - a[0]) + y + w,
			   abs(b[0] - a[-1]) + y + z, abs(b[-1] - a[0]) + x + w, abs(b[-1] - a[-1]) + x + z)
	print(poss)