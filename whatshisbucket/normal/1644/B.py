import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
import random
 
t, = I()
for _ in range(t):
	n, = I()
	used = set()
	p = [i + 1 for i in range(n)]
	iii = 0
	while iii < n:
		random.shuffle(p)
		for i in range(n - 2):
			if p[i] + p[i + 1] == p[i + 2]:
				break
		else:
			if tuple(p) not in used:
				iii += 1
				print(*p)
				used.add(tuple(p))