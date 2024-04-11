import sys
inpu=sys.stdin.readline
prin=sys.stdout.write
I=lambda:[*map(int,inpu().split())]

t = I()[0]
for _ in range(t):
	w, h = I()
	y0 = I()[1:]
	yh = I()[1:]
	x0 = I()[1:]
	xh = I()[1:]
	big = 0
	big = max(big, h * (max(y0) - min(y0)))
	big = max(big, h * (max(yh) - min(yh)))
	big = max(big, w * (max(x0) - min(x0)))
	big = max(big, w * (max(xh) - min(xh)))
	print(big)