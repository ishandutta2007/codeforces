import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	count = {}
	for guy in a:
		if guy in count:
			count[guy] += 1
		else:
			count[guy] = 1
	for guy in count:
		if count[guy] % 2 == 1:
			print(-1)
			break
	else:
		shift = 0
		tlens = []
		adds = []
		while a:
			#print(a)
			val = a[0]
			newind = 1
			while a[newind] != val:
				newind += 1
			tlens.append(newind * 2)
			for i in range(1, newind):
				adds.append((shift + newind + i, a[i]))
			shift += tlens[-1]
			a = a[newind - 1:0:-1] + a[newind + 1:]
		print(len(adds))
		for i in range(len(adds)):
			adds[i] = str(adds[i][0]) + ' ' + str(adds[i][1])
		print('\n'.join(adds))
		print(len(tlens))
		print(*tlens)