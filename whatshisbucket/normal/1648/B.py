import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, c = I()
	a = I()
	contained = [0] * (c + 1)
	for guy in a:
		contained[guy] = 1
	if not contained[1]:
		print("No")
		continue
	partial = [0]
	for i in range(c + 1):
		partial.append(partial[-1] + contained[i])
	bad = False
	for i in range(2, int(c ** .5) + 1):
		j = i + 1
		while j * i <= c:
			if contained[i] and not contained[j]:
				if (j + 1) * i >= len(partial):
					ind = len(partial) - 1
				else:
					ind = (j + 1) * i
				if partial[ind] - partial[j * i] > 0:
					bad = True
			if contained[j] and not contained[i]:
				if (i + 1) * j >= len(partial):
					ind = len(partial) - 1
				else:
					ind = (i + 1) * j
				if partial[ind] - partial[j * i] > 0:
					bad = True
			j += 1

	if bad:
		print("No")
	else:
		print("Yes")