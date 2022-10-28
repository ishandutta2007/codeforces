import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

prec = [float('inf') for i in range(1001)]
prec[1] = 0
for i in range(1, 1000):
	j = 1
	while i // j >= 1:
		if i + i // j <= 1000:
			prec[i + i // j] = min(prec[i + i // j], prec[i] + 1)
		j += 1
t, = I()
for _ in range(t):
	n, k = I()
	b = I()
	c = I()
	benefits = [0]
	for i in range(n):
		#print(benefits)
		new = []
		cost = prec[b[i]]
		for j in range(len(benefits) + cost):
			if j >= len(benefits):
				if j < cost:
					new.append(-float('inf'))
				else:
					new.append(benefits[j - cost] + c[i])
			elif j < cost:
				new.append(benefits[j])
			else:
				new.append(max(benefits[j], benefits[j - cost] + c[i]))
		benefits = new
	#print(benefits)
	print(max(benefits[:(k + 1)]))