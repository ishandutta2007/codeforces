import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

facs = [1]
for i in range(2, 15):
	facs.append(facs[-1] * i)

t, = I()
for _ in range(t):
	n, = I()
	best = 100000
	for i in range(16384):
		tot = 0
		cnt = 0
		for j in range(14):
			if (i >> j) & 1:
				tot += facs[j]
				cnt += 1
		if tot <= n:
			#print(tot, cnt, bin(n - tot).count('1'))
			best = min(best, cnt + bin(n - tot).count('1'))
	print(best)