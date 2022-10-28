import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, k = I()
	a = I()
	present = set(a)
	for guy in present:
		if guy + k in present:
			print("YES")
			break
	else:
		print("NO")