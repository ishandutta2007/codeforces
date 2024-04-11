import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	out = []
	i = 1
	while n - 1 >= 2 * i:
		i *= 2
	j = n - 1
	while j >= i:
		out.append(j)
		j -= 1
	j = 0
	while j < i:
		out.append(j)
		j += 1
	print(*out)