import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	a = I()
	a.sort()
	if a[0] + a[1] == a[2] or (a[1] == a[2] and a[0] % 2 == 0) or (a[0] == a[1] and a[2] % 2 == 0):
		print("YES")
	else:
		print("NO")