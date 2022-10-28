# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	p = I()
	children = [0] * n
	for i in range(n - 1):
		children[p[i] - 1] += 1
	children.append(1)
	children = [guy for guy in children if guy != 0]
	children.sort()
	#print(children)
	steps = len(children)
	x = len(children)
	children = [children[i] - i - 1 for i in range(x)]
	children = [guy for guy in children if guy > 0]
	children.sort(reverse = True)
	#print(children)
	if children:
		l = len(children)
		bonus = 0
		curr = children[0]
		while True:
			done = False
			for i in range(l):
				if children[i] == curr:
					if bonus >= curr:
						done = True
						break
					bonus += 1
					children[i] -= 1
				else:
					break
			if done:
				break
			curr -= 1
		print(steps + bonus)
	else:
		print(steps)