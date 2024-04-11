import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t,=I()
for _ in range(t):
	n, = I()
	a = I()
	count = [0] * (n + 1)
	for guy in a:
		count[guy] += 1
	cum = [count[0]]
	for i in range(n):
		cum.append(cum[-1] + count[i + 1])
	tot = [0]
	for i in range(n):
		tot.append(tot[-1] + count[i + 1] * (i + 1))
	counts = [count[0]]
	point = -1 if count[0] <= 1 else 0
	cover = [-1 if count[0] == 0 else 0]
	for i in range(n):
		if cover[i] == -1:
			cover.append(-1)
		else:
			if count[i + 1] > 1:
				cover.append(cover[-1])
				point = i + 1
				counts.append(count[i + 1])
			elif count[i + 1] == 1:
				cover.append(cover[-1])
				counts.append(count[i + 1])
			else:
				if point < 0:
					cover.append(-1)
				else:
					cover.append(cover[-1] + i + 1 - point)
					counts.append(1)
					counts[point] -= 1
					while counts[point] <= 1 and point >= 0:
						point -= 1
	out = [count[0]]
	for i in range(n):
		if cover[i] == -1:
			out.append(-1)
		else:
			out.append(cover[i] + count[i + 1])
	print(' '.join(str(guy) for guy in out))