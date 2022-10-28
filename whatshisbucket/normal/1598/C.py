t=int(input())
for _ in range(t):
	n=int(input())
	l=list(map(int,input().split()))
	s = sum(l)
	if (2*s)%n !=0:
		print(0)
	else:
		tot = (2*s)//n
		counts = {}
		for guy in l:
			if guy not in counts:
				counts[guy] = 1
			else:
				counts[guy] += 1
		working = 0
		for guy in counts:
			if tot-guy in counts:
				if tot-guy == guy:
					working += counts[guy]*(counts[guy]-1)
				else:
					working += counts[guy]*counts[tot-guy]
		print(working//2)