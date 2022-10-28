import sys
I = lambda:map(int, sys.stdin.readline().split())

t, = I()
for _ in range(t):
	n, = I()
	sml = float('inf')
	big = -float('inf')
	smlcost = 0
	bigcost = 0
	same = False
	samecost = float('inf')
	for i in range(n):
		l, r, c = I()
		if l < sml or l == sml and c < smlcost:
			if l < sml:
				same = False
				samecost = 1 << 30
			sml = l
			smlcost = c
		if r > big or r == big and c < bigcost:
			if r > big:
				same = False
				samecost = 1 << 30
			big = r
			bigcost = c
		if l == sml and r == big:
			same = True
			samecost = min(samecost, c)
		if same:
			print(min(samecost, smlcost + bigcost))
		else:
			print(smlcost + bigcost)