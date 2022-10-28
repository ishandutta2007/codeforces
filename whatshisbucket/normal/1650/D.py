import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	out = []
	for i in range(n, 0, -1):
		ind = a.index(i)
		out.append((ind + 1) % i)
		new = []
		for j in range(i):
			new.append(a[(j + ind + 1) % i])
		#print(new)
		a = new
	print(*(out[::-1]))