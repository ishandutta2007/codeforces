import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	p = I()
	start = 0
	while start < n and p[start] == start + 1:
		start += 1
	if start == n:
		print(*p)
	else:
		x = p.index(start + 1)
		l = p[:start] + p[x:start:-1] + [p[start]] + p[x + 1:]
		#print(p[:start], p[x:start], p[start], p[x + 1:])
		print(*l)