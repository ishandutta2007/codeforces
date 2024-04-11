#import sys
#I = lambda:map(int, sys.stdin.readline().split())

t = int(input())
for _ in range(t):
	n = int(input())
	seen = [0] * n
	cycles = []
	for i in range(n):
		if not seen[i]:
			cycle = []
			print('?', i + 1)
			y = int(input())
			cycle.append(y - 1)
			seen[y - 1] = 1
			print('?', i + 1)
			x = int(input())
			while x != y:
				cycle.append(x - 1)
				seen[x - 1] = 1
				print('?', i + 1)
				x = int(input())
			cycles.append(cycle)
	p = [0] * n
	for cycle in cycles:
		for i in range(len(cycle)):
			p[cycle[i - 1]] = cycle[i] + 1

	print('!', *p)