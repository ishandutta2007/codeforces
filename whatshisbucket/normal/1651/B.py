import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	if 3 ** (n - 1) > 10**9:
		print("NO")
	else:
		print("YES")
		print(*[3**i for i in range(n)])